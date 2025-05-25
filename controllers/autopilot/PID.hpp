#pragma once

class PID {
public:
  PID(double kp, double ki, double kd);
  double compute(double error);
  void reset();
  void setGains(double kp, double ki, double kd);

private:
  double kp, ki, kd;
  double prevError;
  double integral;
};

double applyPID(double yellow_line_angle);

