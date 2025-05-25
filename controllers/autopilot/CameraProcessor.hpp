#pragma once
#include <webots/Camera.hpp>

class CameraProcessor {
 public:
  double process(const unsigned char* image, webots::Camera* camera);
  static double detectLaneOffset(const unsigned char* image, int width, int height, double fov);
  static double detectLaneAngle(const unsigned char* image, int width, int height);

};
