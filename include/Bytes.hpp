// @copyright 2024 Joshua Austill
// @brief This file will contain utility functions for working with bytes.

#ifndef BYTES_HPP_
#define BYTES_HPP_

#include <cstdint>

namespace SeaDash {
namespace Bytes {
template <typename T>
T getNthByte(T value, uint8_t n) {
    if (n > sizeof(T)) {
        return 0;
    }
  return (value >> ((n - 1) * 8)) & 0xFF;
}
}  // namespace Bytes
}  // namespace SeaDash

#endif  // BYTES_HPP_
