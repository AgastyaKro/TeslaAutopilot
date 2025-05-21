#include "Autopilot.hpp"
#include <iostream>

Autopilot::Autopilot(webots::Robot& robot) {
  this->robot = &robot;

  leftSteer = robot.getMotor("left_steer");
  rightSteer = robot.getMotor("right_steer");

  leftFrontWheel = robot.getMotor("left_front_wheel");
  rightFrontWheel = robot.getMotor("right_front_wheel");

  camera = robot.getCamera("camera");
  lidar = robot.getLidar("Sick LMS 291");

  // Safety checks
  if (!leftSteer || !rightSteer || !leftFrontWheel || !rightFrontWheel)
    std::cerr << "[ERROR] One or more motors not found!" << std::endl;

  if (camera)
    camera->enable(50);
  if (lidar)
    lidar->enable(50);
}

void Autopilot::step(int timeStep) {
  // Set fixed values for demo
  if (leftSteer && rightSteer) {
    leftSteer->setPosition(0.0);
    rightSteer->setPosition(0.0);
  }

  if (leftFrontWheel && rightFrontWheel) {
    leftFrontWheel->setVelocity(5.0);
    rightFrontWheel->setVelocity(5.0);
  }
}
