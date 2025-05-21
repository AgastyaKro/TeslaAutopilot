#include <webots/Robot.hpp>
#include <webots/Device.hpp>  // For getDeviceByIndex()
#include <iostream>
#include "Autopilot.hpp"

#define TIME_STEP 50

int main() {
  webots::Robot robot;

  // List all available device names for debugging
  int deviceCount = robot.getNumberOfDevices();
  std::cout << "=== Webots Devices Detected ===" << std::endl;
  for (int i = 0; i < deviceCount; ++i) {
    const webots::Device *dev = robot.getDeviceByIndex(i);
    std::cout << "[Device] " << dev->getName() << std::endl;
  }
  std::cout << "================================" << std::endl;

  // Launch your autopilot
  Autopilot autopilot(robot);

  while (robot.step(TIME_STEP) != -1) {
    autopilot.step(TIME_STEP);
  }

  return 0;
}
