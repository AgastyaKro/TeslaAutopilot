#include "ObstacleAvoidance.hpp"
#include "utils.hpp"

double ObstacleAvoidance::process(webots::Lidar* lidar, const float* data, double* obstacle_dist) {
  int width = lidar->getHorizontalResolution();
  double fov = lidar->getFov();
  int count = 0;
  int sumx = 0;
  *obstacle_dist = 0.0;

  for (int x = width / 2 - 20; x < width / 2 + 20; ++x) {
    float range = data[x];
    if (range < 20.0) {
      sumx += x;
      ++count;
      *obstacle_dist += range;
    }
  }

  if (count == 0) return UNKNOWN;
  *obstacle_dist /= count;
  return ((double)sumx / count / width - 0.5) * fov;
}
