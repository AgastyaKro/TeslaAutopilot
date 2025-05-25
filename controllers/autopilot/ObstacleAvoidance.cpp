#include "ObstacleAvoidance.hpp"

bool ObstacleAvoidance::detect(const float* data, int width, double fov, double& outAngle, double& outDistance) {
  const int HALF_AREA = 20;
  int sumX = 0;
  int count = 0;
  double sumDist = 0;

  for (int i = width / 2 - HALF_AREA; i < width / 2 + HALF_AREA; ++i) {
    if (data[i] < 20.0) {
      sumX += i;
      sumDist += data[i];
      count++;
    }
  }

  if (count == 0)
    return false;

  outAngle = ((static_cast<double>(sumX) / count) / width - 0.5) * fov;
  outDistance = sumDist / count;
  return true;
}
