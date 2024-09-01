// @copyright 2024 Joshua Austill
// @brief This file will contain utility functions for mathy type things.

#ifndef MATH_HPP_
#define MATH_HPP_

#include <cmath>
namespace SeaDash {
namespace Math {
template <typename T>
T addNRestrained(T input, T n, T min, T max) {
  // This function adds n to input, but keeps the result between min and max.
  T result = (floor((input + n) / n)) * n;
  if (result < min) return min;
  if (result > max) return max;
  return result;
}
}  // namespace Math
}  // namespace SeaDash
#endif  // MATH_HPP_
