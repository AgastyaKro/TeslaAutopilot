#pragma once
#include <webots/Lidar.hpp>

class ObstacleAvoidance {
 public:
  double process(webots::Lidar* lidar, const float* data, double* obstacle_dist);
};
