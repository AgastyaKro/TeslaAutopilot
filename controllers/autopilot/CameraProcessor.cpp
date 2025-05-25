#include "CameraProcessor.hpp"
#include "utils.hpp"

double CameraProcessor::process(const unsigned char* image, webots::Camera* camera) {
  const unsigned char REF[3] = {95, 187, 203};
  int width = camera->getWidth();
  int height = camera->getHeight();
  int count = 0;
  int sumx = 0;

  for (int i = 0; i < width * height; ++i) {
    const unsigned char* pixel = image + 4 * i;
    if (colorDiff(pixel, REF) < 30) {
      sumx += i % width;
      count++;
    }
  }

  if (count == 0) return UNKNOWN;
  return ((double)sumx / count / width - 0.5) * camera->getFov();
}

double CameraProcessor::detectLaneOffset(const unsigned char* image, int width, int height, double fov){
  const unsigned char YELLOW[3] = {95, 187, 203};
  int numPixels = width * height;
  int sumX = 0;
  int count = 0;

  for (int i = 0; i < numPixels; i++){
    const unsigned char* pixel = image + 4 * i; // every image is red, blue, green, alpha
    int diff = 0;
    for (int c = 0; c < 3; c++){
      diff += std::abs(pixel[c] - YELLOW[c]);
      if (diff < 30){
        sumX += i % width;
        count++;
      }
    }
  }
  
  if (count == 0){
    return NAN;
  }
  double avgX = static_cast<double>(sumX) / count;
  return ((avgX / width) - .5) * fov;
}

double CameraProcessor::detectLaneAngle(const unsigned char* image, int width, int height){
  // 0,0 is the top left pixel
  const unsigned char YELLOW[3] = {95, 187, 203};
  int y1 = height - 1; // bottom row
  int y2 = height / 2; // middle row
  int x1sum = 0;
  int x1count = 0;
  int x2sum = 0;
  int x2count = 0;

  for (int x = 0; x < width; x++){
    const unsigned char* pixel1 = image + 4 * (y1 * width + x);
    const unsigned char* pixel2 = image + 4 * (y2 * width + x);
    int diff1 = 0;
    int diff2 = 0;

    for (int c = 0; c < 3; c++){
      diff1 += std::abs(pixel1[c]- YELLOW[c]);
      diff2 += std::abs(pixel2[c] - YELLOW[c]);
    }

    if (diff1 < 30) {
      x1sum += x;
      x1count++;
    }

    if (diff2 < 30) {
      x2sum += x;
      x2count++;
    }
  }
  
  if (x1count == 0 || x2count == 0)
    return 0.0;
  
  double x1 = static_cast<double>(x1sum) / x1count;
  double x2 = static_cast<double>(x2sum) / x2count;
  double dy = static_cast<double>(y2 - y1);
  double dx = x2 - x1;
  return std::atan2(dy, dx);



}
