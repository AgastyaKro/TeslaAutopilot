#pragma once

#include <webots/Camera.hpp>
#include <webots/Lidar.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

class Autopilot {
public:
  Autopilot(webots::Robot& robot);
  void step(int timeStep);  // Called every timestep to update vehicle control

private:
  // Pointer to Webots Robot
  webots::Robot* robot;

  // Steering motors
  webots::Motor* leftSteer;
  webots::Motor* rightSteer;

  // Driving motors
  webots::Motor* leftFrontWheel;
  webots::Motor* rightFrontWheel;

  // Sensors
  webots::Camera* camera;
  webots::Lidar* lidar;

  // Display
  webots::Display* display;

};
