#include "Autopilot.hpp"
#include "CameraProcessor.hpp"
#include "ObstacleAvoidance.hpp"
#include "PID.hpp"
#include <webots/Display.hpp>
#include <iostream>
#include <cmath>

// External utility functions
extern double filter_angle(double new_value);
extern void updateDisplay(webots::Display* display, double speed);


PID pidSteering(0.25, 0.006, 2.0);  // example gains

Autopilot::Autopilot(webots::Robot& robot) {
  this->robot = &robot;

  leftSteer = robot.getMotor("left_steer");
  rightSteer = robot.getMotor("right_steer");

  leftFrontWheel = robot.getMotor("left_front_wheel");
  rightFrontWheel = robot.getMotor("right_front_wheel");

  camera = robot.getCamera("camera");
  lidar = robot.getLidar("Sick LMS 291");

  if (!leftSteer || !rightSteer || !leftFrontWheel || !rightFrontWheel)
    std::cerr << "[ERROR] One or more motors not found!" << std::endl;

  if (camera)
    camera->enable(50);
  if (lidar)
    lidar->enable(50);


  display = robot.getDisplay("display");
  if (display)
    std::cout << "[INFO] Display initialized.\n";
  else
    std::cerr << "[WARN] Display not found.\n";

}

void Autopilot::step(int timeStep) {
  std::cout << "[DEBUG] step() called" << std::endl;
  if (!camera) std::cout << "[ERROR] camera is null!" << std::endl;
  if (!lidar) std::cout << "[ERROR] lidar is null!" << std::endl;

  if (!camera || !lidar)
    return;

  const unsigned char* image = camera->getImage();
  const float* lidarData = lidar->getRangeImage();

  double offset = CameraProcessor::detectLaneOffset(image, camera->getWidth(), camera->getHeight(), camera->getFov());
  double rawAngle = CameraProcessor::detectLaneAngle(image, camera->getWidth(), camera->getHeight());
  double angle = filter_angle(rawAngle);

  if (std::isnan(offset)) {
    offset = 0.0;
    std::cerr << "[WARN] Yellow line not detected — defaulting to 0 steer\n";
    return;
  }
  double combinedError = offset + 0.4 * angle;
  std::cout << "[Control] Offset: " << offset
          << ", Raw Angle: " << rawAngle
          << ", Filtered: " << angle
          << ", Combined Error: " << combinedError << std::endl;
  double steer = applyPID(combinedError);
  steer = std::max(std::min(steer, 0.5), -0.5); 

  double obsAngle = 0.0, obsDist = 0.0;
  bool hasObstacle = ObstacleAvoidance::detect(lidarData, lidar->getHorizontalResolution(), lidar->getFov(), obsAngle, obsDist);

  double speed = (hasObstacle && obsDist < 2.0) ? 0.0 : 20.0;
  std::cout << "[Obstacle] Detected: " << hasObstacle
          << ", Angle: " << obsAngle
          << ", Distance: " << obsDist << std::endl;
          
  if (leftSteer && rightSteer) {
    leftSteer->setPosition(steer);
    rightSteer->setPosition(steer);
  }

  if (leftFrontWheel && rightFrontWheel) {
    leftFrontWheel->setVelocity(speed);
    rightFrontWheel->setVelocity(speed);
  }

  if (display)
  updateDisplay(display, leftFrontWheel->getVelocity());
}
