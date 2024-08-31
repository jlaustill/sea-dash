#ifndef SEADASH_BITUTILS_HPP
#define SEADASH_BITUTILS_HPP
#include <math.h>

#include <climits>

namespace SeaDash {
namespace Bits {

template <typename T>
unsigned getMaxN() {
  return CHAR_BIT * sizeof(T);
}

template <typename T>
T getNOnes(unsigned n) {
  const unsigned max_n = getMaxN<T>();

  if (n == 0) return 0;           // No bits set
  if (n >= max_n) return ~T(0);   // All bits set

  return (static_cast<T>(1) << n) - 1;
}


template <typename T>
T getNOnesAt(unsigned n, unsigned offset) {
  return getNOnes<T>(n) << offset;
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

  if (offset >= max_n || n == 0) {
    return value;  // Offset is out of bounds or no bits to set
  }

  if (offset + n > max_n) {
    n = max_n - offset;  // Constrain n to stay within the bounds
  }

  bits = getNBits<T>(bits, 0, n);  // Make sure not to set too many bits

  // Zero out the bits in the target range and set new bits
  value &= ~getNOnesAt<T>(n, offset);
  value |= bits << offset;

  return value;
}


}  // namespace Bits
}  // namespace SeaDash

#endif  // SEADASH_BITUTILS_HPP
