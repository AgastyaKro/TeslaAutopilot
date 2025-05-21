#pragma once

class PID {
 public:
  PID(double kp, double ki, double kd);
  double update(double error);

 private:
  double kp, ki, kd;
  double previous = 0.0;
  double integral = 0.0;
};
