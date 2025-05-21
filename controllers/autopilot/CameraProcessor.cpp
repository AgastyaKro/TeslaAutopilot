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
