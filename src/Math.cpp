#include "Math.hpp"

namespace SeaDash {
namespace Math {

int addBAndB(int a, int b) {
  // This function adds two integers a and b and returns the result.
  return a + b;
}

template <typename T>
T addNRestrained(T input, T n, T min, T max) {
  // This function adds n to input, but keeps the result between min and max.
  T result = ((input + n) / n) * n;
  if (result < min) return min;
  if (result > max) return max;
  return result;
}
}  // namespace Math
}  // namespace SeaDash
