#include <webots/Display.hpp>
#include <webots/Robot.hpp>
#include <iostream>
#include <cmath>

void updateDisplay(webots::Display* display, double speed) {
  if (!display)
    return;

  const double NEEDLE_LENGTH = 50.0;
  double alpha = speed / 260.0 * 3.72 - 0.27;
  int x = -NEEDLE_LENGTH * cos(alpha);
  int y = -NEEDLE_LENGTH * sin(alpha);

  display->setColor(0xFF0000);  // Red needle
  display->drawLine(100, 95, 100 + x, 95 + y);

  std::cout << "[Display] Drawing speed needle at speed: " << speed << std::endl;
}
