// Copyright: Joshua Austill 2024

#ifndef SEADASH_INT32_INCREMENTAL_CIRCULAR_AVERAGE_CPP_
#define SEADASH_INT32_INCREMENTAL_CIRCULAR_AVERAGE_CPP_

#include "Uint32/IncrementalCircularAverage.hpp"

namespace SeaDash {
namespace Uint32 {

IncrementalCircularAverage::IncrementalCircularAverage(uint8_t bufferSize)
    : size(bufferSize), data(new uint32_t[bufferSize]()) {}

IncrementalCircularAverage::~IncrementalCircularAverage() { delete[] data; }

void IncrementalCircularAverage::addValue(uint32_t newValue) {
  if (full) {
    // Subtract the value being replaced from the sum
    sum -= data[index];
  }

  // Add the new value to the sum
  sum += newValue;
  data[index] = newValue;

  // Move the index to the next position
  index = (index + 1) % size;

  // Check if the buffer is full
  if (index == 0) {
    full = true;
  }
}

uint32_t IncrementalCircularAverage::getAverage() const {
  if (full) {
    return sum / size;  // Average of all values when the buffer is full
  } else if (index > 0) {
    return sum / index;  // Average of the values added so far
  } else {
    return 0;  // No values have been added
  }
}

}  // namespace Uint32
}  // namespace SeaDash

#endif  // SEADASH_INT32_INCREMENTAL_CIRCULAR_AVERAGE_CPP_
