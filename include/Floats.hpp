// @copyright 2024 Joshua Austill
// @brief This file will contain utility functions for working with floats.

#ifndef FLOATS_HPP_
#define FLOATS_HPP_

namespace SeaDash {
namespace Floats {
template <typename T>
T mapf(T x, T in_min, T in_max, T out_min, T out_max) {
  if (in_min == in_max) {
    // Handle division by zero error or invalid input range
    // You can choose to return a default value or throw an exception
    return static_cast<T>(0);  // Default value
  }

  // Compute the scaling factor
  T scale = (out_max - out_min) / (in_max - in_min);

  // Map the value to the output range
  return (x - in_min) * scale + out_min;
}

}  // namespace Floats
}  // namespace SeaDash

#endif  // FLOATS_HPP_
