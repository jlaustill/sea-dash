#ifndef SEADASH_BITUTILS_HPP
#define SEADASH_BITUTILS_HPP
#include <math.h>

#include <climits>

namespace SeaDash {
namespace Bits {

template <typename T>
T getNOnes(unsigned n) {
  return (static_cast<T>(1) << n) - 1;
}

template <typename T>
T getNOnesAt(unsigned n, unsigned offset) {
  return getNOnes<T>(n) << offset;
}

template <typename T>
unsigned getMaxN() {
  return CHAR_BIT * sizeof(T);
}

template <typename T>
T getNBits(T value, unsigned offset, unsigned n) {
  const unsigned max_n = getMaxN<T>();
  if (offset >= max_n)
    return 0;       /* value is padded with infinite zeros on the left */
  value >>= offset; /* drop offset bits */
  if (n >= max_n) return value;         /* all  bits requested */
  const unsigned mask = getNOnes<T>(n); /* n '1's */
  return value & mask;
}

template <typename T>
T setNBitsAt(T value, T bits, unsigned offset, unsigned n) {
  const unsigned max_n = getMaxN<T>();
  // first we check for in bounds offset
  if (offset >= max_n || offset + n >= max_n) {
    return value;  // offset is out of bounds
  }
  bits = getNBits(bits, 0, n);  // Make sure not to set too many bits
  // first we need to zero out the bits we are going to set
  value &= ~getNOnesAt<T>(n, offset);
  value |= bits << n;

  return value;
}
}  // namespace Bits
}  // namespace SeaDash

#endif  // SEADASH_BITUTILS_HPP
