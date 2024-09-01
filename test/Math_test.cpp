// @copyright 2024 Joshua Austill
// @brief This files will contains tests for the Math namespace.

#include "Math.hpp"

#include <gtest/gtest.h>

namespace SeaDash {
namespace Math {

// Test standard cases with float
TEST(AddNRestrainedTest, FloatStandardCases) {
  EXPECT_FLOAT_EQ(addNRestrained(5.0f, 3.0f, 0.0f, 10.0f), 6.0f);
  EXPECT_FLOAT_EQ(addNRestrained(5.0f, -2.0f, 0.0f, 10.0f), 4.0f);
  EXPECT_FLOAT_EQ(addNRestrained(5.0f, 10.0f, 0.0f, 10.0f), 10.0f);
  EXPECT_FLOAT_EQ(addNRestrained(-5.0f, 10.0f, 0.0f, 10.0f), 0.0f);
  EXPECT_FLOAT_EQ(addNRestrained(5.0f, -10.0f, -20.0f, -10.0f), -10.0f);
}

// Test boundary cases with float
TEST(AddNRestrainedTest, FloatBoundaryCases) {
  EXPECT_FLOAT_EQ(addNRestrained(0.0f, 1.0f, 0.0f, 5.0f), 1.0f);
  EXPECT_FLOAT_EQ(addNRestrained(5.0f, -5.0f, 0.0f, 10.0f), 0.0f);
  EXPECT_FLOAT_EQ(addNRestrained(10.0f, 5.0f, 0.0f, 10.0f), 10.0f);
  EXPECT_FLOAT_EQ(addNRestrained(5.0f, 5.0f, 0.0f, 10.0f), 10.0f);
}

// Test standard cases with double
TEST(AddNRestrainedTest, DoubleStandardCases) {
  EXPECT_DOUBLE_EQ(addNRestrained(5.0, 3.0, 0.0, 10.0), 6.0);
  EXPECT_DOUBLE_EQ(addNRestrained(5.0, -2.0, 0.0, 10.0), 4.0);
  EXPECT_DOUBLE_EQ(addNRestrained(5.0, 10.0, 0.0, 10.0), 10.0);
  EXPECT_DOUBLE_EQ(addNRestrained(-5.0, 10.0, 0.0, 10.0), 0.0);
  EXPECT_DOUBLE_EQ(addNRestrained(5.0, -10.0, -20.0, -10.0), -10.0);
}

// Test boundary cases with double
TEST(AddNRestrainedTest, DoubleBoundaryCases) {
  EXPECT_DOUBLE_EQ(addNRestrained(0.0, 1.0, 0.0, 5.0), 1.0);
  EXPECT_DOUBLE_EQ(addNRestrained(5.0, -5.0, 0.0, 10.0), 0.0);
  EXPECT_DOUBLE_EQ(addNRestrained(10.0, 5.0, 0.0, 10.0), 10.0);
  EXPECT_DOUBLE_EQ(addNRestrained(5.0, 5.0, 0.0, 10.0), 10.0);
}

}  // namespace Math
}  // namespace SeaDash
