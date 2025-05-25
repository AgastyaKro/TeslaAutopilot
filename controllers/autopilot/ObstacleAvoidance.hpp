#pragma once

class ObstacleAvoidance {
public:
  static bool detect(const float* data, int width, double fov, double& outAngle, double& outDistance);
};
