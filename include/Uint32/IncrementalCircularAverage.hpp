// Copyright: Joshua Austill 2024

#ifndef UINT32_INCREMENTALCIRCULARAVERAGE_HPP_
#define UINT32_INCREMENTALCIRCULARAVERAGE_HPP_

#include <cstdint>

namespace SeaDash {
namespace Uint32 {

class IncrementalCircularAverage {
 private:
  uint32_t* data;     // Pointer to dynamically allocated array
  uint8_t size;       // Size of the buffer
  uint8_t index = 0;  // Current index in the circular buffer
  uint64_t sum = 0;   // Running sum of the values in the buffer
  bool full = false;  // Flag to indicate if the buffer is full

 public:
  // Constructor that accepts the buffer size
  explicit IncrementalCircularAverage(uint8_t bufferSize);

  // Destructor to clean up dynamically allocated memory
  ~IncrementalCircularAverage();

  void addValue(uint32_t newValue);

  uint32_t getAverage() const;
};

}  // namespace Uint32
}  // namespace SeaDash

#endif  // UINT32_INCREMENTALCIRCULARAVERAGE_HPP_
