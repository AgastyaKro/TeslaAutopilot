#include "PID.hpp"

PID::PID(double kp_, double ki_, double kd_)
    : kp(kp_), ki(ki_), kd(kd_) {}

double PID::update(double error) {
  double diff = error - previous;
  integral += error;
  previous = error;
  return kp * error + ki * integral + kd * diff;
}
