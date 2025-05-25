#include <cmath>
#include <iostream>

double filter_angle(double new_value) {
  const int FILTER_SIZE = 3;
  static bool first_call = true;
  static double old_values[FILTER_SIZE];

  if (first_call || std::isnan(new_value)) {
    first_call = false;
    for (int i = 0; i < FILTER_SIZE; ++i)
      old_values[i] = 0.0;
    std::cout << "[Filter] Resetting filter buffer" << std::endl;
  } else {
    for (int i = 0; i < FILTER_SIZE - 1; ++i)
      old_values[i] = old_values[i + 1];
  }

  if (std::isnan(new_value)) {
    std::cout << "[Filter] Input is NaN; returning NaN" << std::endl;
    return NAN;
  }

  old_values[FILTER_SIZE - 1] = new_value;
  double sum = 0.0;
  for (int i = 0; i < FILTER_SIZE; ++i)
    sum += old_values[i];

  double avg = sum / FILTER_SIZE;
  std::cout << "[Filter] Filtered angle: " << avg << std::endl;
  return avg;
}
