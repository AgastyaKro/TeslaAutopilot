#include "PID.hpp"
#include <cmath>
#include <iostream>

PID::PID(double kp, double ki, double kd)
  : kp(kp), ki(ki), kd(kd), prevError(0.0), integral(0.0) {}

double PID::compute(double error) {
  double derivative = error - prevError;
  integral += error;

  // Anti-windup
  if (std::signbit(error) != std::signbit(prevError))
    integral = 0.0;

  prevError = error;

  double output = kp * error + ki * integral + kd * derivative;
  std::cout << "[PID] error: " << error
            << ", integral: " << integral
            << ", derivative: " << derivative
            << ", output: " << output << std::endl;
  return output;
}

void PID::reset() {
  prevError = 0.0;
  integral = 0.0;
}

void PID::setGains(double kp, double ki, double kd) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
}

double applyPID(double yellow_line_angle) {
  static double oldValue = 0.0;
  static double integral = 0.0;

  std::cout << "[PID] Input angle: " << yellow_line_angle << std::endl;

  // Anti-windup logic
  if (std::signbit(yellow_line_angle) != std::signbit(oldValue)) {
    integral = 0.0;
    std::cout << "[PID] Flipped sign; resetting integral." << std::endl;
  }

  double diff = yellow_line_angle - oldValue;

  if (integral < 30 && integral > -30)
    integral += yellow_line_angle;

  oldValue = yellow_line_angle;

  double result = 0.25 * yellow_line_angle + 0.006 * integral + 2.0 * diff;
  std::cout << "[PID] Output: " << result << std::endl;
  return result;
}
