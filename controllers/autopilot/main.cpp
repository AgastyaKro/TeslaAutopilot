#include <webots/Robot.hpp>
#include "Autopilot.hpp"

int main() {
  webots::Robot robot;
  Autopilot autopilot(robot);

  int timeStep = (int)robot.getBasicTimeStep();
  while (robot.step(timeStep) != -1) {
    autopilot.step(timeStep);
  }

  return 0;
}
