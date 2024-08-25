#ifndef SEADASH_BITUTILS_HPP
#define SEADASH_BITUTILS_HPP

namespace SeaDash {
namespace Bits {

unsigned getNOnes(unsigned n);

unsigned getNOnesAt(unsigned n, unsigned offset);

unsigned getMaxN();

unsigned getNBits(unsigned value, unsigned offset, unsigned n);

unsigned setNBitsAt(unsigned value, unsigned bits, unsigned offset, unsigned n);
}  // namespace Bits
}  // namespace SeaDash

#endif  // SEADASH_BITUTILS_HPP
