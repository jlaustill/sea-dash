
#include <SeaDash.hpp>

#include <gtest/gtest.h>

// Test for standard mapping cases
TEST(mapfTest, StandardCases) {
  // Test with float
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(5.0f, 0.0f, 10.0f, 0.0f, 100.0f),
                  50.0f);
  // Test with double
  EXPECT_DOUBLE_EQ(SeaDash::Floats::mapf(2.5, 0.0, 5.0, 0.0, 10.0), 5.0);
  // Test with long double
  EXPECT_DOUBLE_EQ(SeaDash::Floats::mapf(3.0L, 1.0L, 4.0L, 10.0L, 40.0L),
                   30.0L);
}

// Test for edge cases
TEST(SmapfTest, EdgeCases) {
  // Test for division by zero (in_min == in_max)
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(5.0f, 10.0f, 10.0f, 0.0f, 100.0f),
                  0.0f);

  // Test where x is exactly in_min or in_max
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(0.0f, 0.0f, 10.0f, 0.0f, 100.0f), 0.0f);
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(10.0f, 0.0f, 10.0f, 0.0f, 100.0f),
                  100.0f);

  // Test where x is out of the input range (extrapolation)
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(-5.0f, 0.0f, 10.0f, 0.0f, 100.0f),
                  -50.0f);
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(15.0f, 0.0f, 10.0f, 0.0f, 100.0f),
                  150.0f);

  // Test where output range is inverted (out_min > out_max)
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(5.0f, 0.0f, 10.0f, 100.0f, 0.0f),
                  50.0f);

  // Test where input range is inverted (in_min > in_max)
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(5.0f, 10.0f, 0.0f, 0.0f, 100.0f),
                  50.0f);

  // Test where both input and output ranges are inverted
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(5.0f, 10.0f, 0.0f, 100.0f, 0.0f),
                  50.0f);

  // Test with very small numbers close to zero (precision test)
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(1e-7f, 0.0f, 1e-6f, 0.0f, 1.0f), 0.1f);
  EXPECT_DOUBLE_EQ(SeaDash::Floats::mapf(1e-10, 0.0, 1e-9, 0.0, 1.0), 0.1);
}

// Test for identical input and output ranges
TEST(mapfTest, IdenticalRanges) {
  EXPECT_FLOAT_EQ(SeaDash::Floats::mapf(5.0f, 0.0f, 10.0f, 0.0f, 10.0f), 5.0f);
  EXPECT_DOUBLE_EQ(SeaDash::Floats::mapf(5.0, 0.0, 10.0, 0.0, 10.0), 5.0);
}
