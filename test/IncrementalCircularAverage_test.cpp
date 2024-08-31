#include "Uint32/IncrementalCircularAverage.hpp"

#include <gtest/gtest.h>

namespace {

using SeaDash::Uint32::IncrementalCircularAverage;

TEST(IncrementalCircularAverageTest, InitialAverageIsZero) {
  IncrementalCircularAverage avg(3);
  EXPECT_EQ(avg.getAverage(), 0);
}

TEST(IncrementalCircularAverageTest, SingleValueAverage) {
  IncrementalCircularAverage avg(3);
  avg.addValue(10);
  EXPECT_EQ(avg.getAverage(), 10);
}

TEST(IncrementalCircularAverageTest, MultipleValuesAverage) {
  IncrementalCircularAverage avg(3);
  avg.addValue(10);
  avg.addValue(20);
  EXPECT_EQ(avg.getAverage(), 15);
}

TEST(IncrementalCircularAverageTest, BufferFullAverage) {
  IncrementalCircularAverage avg(3);
  avg.addValue(10);
  avg.addValue(20);
  avg.addValue(30);
  EXPECT_EQ(avg.getAverage(), 20);
}

TEST(IncrementalCircularAverageTest, CircularBufferOverwrite) {
  IncrementalCircularAverage avg(3);
  avg.addValue(10);
  avg.addValue(20);
  avg.addValue(30);
  avg.addValue(40);  // Overwrites the first value (10)
  EXPECT_EQ(avg.getAverage(), (20 + 30 + 40) / 3);
}

TEST(IncrementalCircularAverageTest, BufferNotFullAverage) {
  IncrementalCircularAverage avg(3);
  avg.addValue(10);
  avg.addValue(20);
  EXPECT_EQ(avg.getAverage(), 15);  // Average of 10 and 20
}

TEST(IncrementalCircularAverageTest, AllValuesZero) {
  IncrementalCircularAverage avg(3);
  avg.addValue(0);
  avg.addValue(0);
  avg.addValue(0);
  EXPECT_EQ(avg.getAverage(), 0);
}

TEST(IncrementalCircularAverageTest, LargeValues) {
  IncrementalCircularAverage avg(3);
  avg.addValue(UINT32_MAX);
  avg.addValue(UINT32_MAX);
  avg.addValue(UINT32_MAX);
  EXPECT_EQ(avg.getAverage(), UINT32_MAX);
}

TEST(IncrementalCircularAverageTest, MixedValues) {
  IncrementalCircularAverage avg(3);
  avg.addValue(0);
  EXPECT_EQ(avg.getAverage(), 0);
  avg.addValue(UINT32_MAX);
  EXPECT_EQ(avg.getAverage(), UINT32_MAX / 2);
  avg.addValue(UINT32_MAX / 2U);

  uint64_t expected_sum = static_cast<uint64_t>(0) +
                          static_cast<uint64_t>(UINT32_MAX) +
                          static_cast<uint64_t>(UINT32_MAX / 2U);
  uint32_t expected_avg = expected_sum / 3;

  EXPECT_EQ(avg.getAverage(), expected_avg);
}

TEST(IncrementalCircularAverageTest, BufferSizeOne) {
  IncrementalCircularAverage avg(1);
  avg.addValue(10);
  EXPECT_EQ(avg.getAverage(), 10);
  avg.addValue(20);  // Overwrites the only value
  EXPECT_EQ(avg.getAverage(), 20);
}

TEST(IncrementalCircularAverageTest, BufferOverwrite) {
  IncrementalCircularAverage avg(3);
  avg.addValue(10);
  avg.addValue(20);
  avg.addValue(30);
  avg.addValue(40);
  avg.addValue(50);
  EXPECT_EQ(avg.getAverage(), (30 + 40 + 50) / 3);
}

TEST(IncrementalCircularAverageTest, BufferFullMultipleCycles) {
  IncrementalCircularAverage avg(3);
  avg.addValue(1);
  avg.addValue(2);
  avg.addValue(3);
  avg.addValue(4);  // Overwrites the first value (1)
  avg.addValue(5);  // Overwrites the second value (2)
  EXPECT_EQ(avg.getAverage(), (3 + 4 + 5) / 3);
}

TEST(IncrementalCircularAverageTest, DestructorTest) {
  IncrementalCircularAverage* avg = new IncrementalCircularAverage(3);
  avg->addValue(10);
  avg->addValue(20);
  EXPECT_EQ(avg->getAverage(), 15);
  delete avg;  // Ensure no crashes on deletion
}

}  // namespace
