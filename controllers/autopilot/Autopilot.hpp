#pragma once

#include <webots/Motor.hpp>
#include <webots/Camera.hpp>
#include <webots/Lidar.hpp>
#include <webots/Robot.hpp>

class Autopilot {
public:
  Autopilot(webots::Robot& robot);
  void step(int timeStep);

private:
  webots::Robot* robot;

  // Motors
  webots::Motor* leftSteer;
  webots::Motor* rightSteer;
  webots::Motor* leftFrontWheel;
  webots::Motor* rightFrontWheel;

  // Sensors
  webots::Camera* camera;
  webots::Lidar* lidar;
};
