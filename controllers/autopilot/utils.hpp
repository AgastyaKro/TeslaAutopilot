#pragma once
#include <cmath>

constexpr double UNKNOWN = std::numeric_limits<double>::quiet_NaN();

inline int colorDiff(const unsigned char a[3], const unsigned char b[3]) {
  int diff = 0;
  for (int i = 0; i < 3; ++i)
    diff += std::abs(static_cast<int>(a[i]) - static_cast<int>(b[i]));
  return diff;
}
