#pragma once
#include <webots/Camera.hpp>

class CameraProcessor {
 public:
  double process(const unsigned char* image, webots::Camera* camera);
};
