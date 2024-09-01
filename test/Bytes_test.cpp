// @copyright 2024 Joshua Austill
// @brief This file will test the Bytes utility functions.

#include "Bytes.hpp"

#include "gtest/gtest.h"

TEST(BytesTest, GetNthByte) {
  // Test getting the 0th byte of a 32-bit value
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x12345678, 1), 0x78);

  // Test getting the 1st byte of a 32-bit value
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x12345678, 2), 0x56);

  // Test getting the 2nd byte of a 32-bit value
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x12345678, 3), 0x34);

  // Test getting the 3rd byte of a 32-bit value
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x12345678, 4), 0x12);
}

TEST(BytesTest, BoundaryValues) {
  // Test with a uint8_t value, where n should only be 1
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint8_t>(0xAB, 1), 0xAB);

  // Test with n = 0 (out of bounds)
  // If not handling this case in the function, it's better to avoid testing it
  // directly since it might cause undefined behavior. Uncomment if you handle
  // this case: EXPECT_EQ(SeaDash::Bytes::getNthByte(0x12345678, 0), 0x00);  //
  // or handle as needed

  // Test with n = 5 (out of bounds for a 32-bit value)
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x12345678, 5),
            0x00);  // Should be 0x00 since there's no 5th byte

  // Test with n = 8 (out of bounds for a 32-bit value but valid for uint64_t)
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x12345678, 8), 0x00);  // Should be 0x00
}

TEST(BytesTest, DifferentDataTypes) {
  // Test with uint16_t value
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint16_t>(0x1234, 1), 0x34);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint16_t>(0x1234, 2), 0x12);

  // Test with uint8_t value
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint8_t>(0xAB, 1), 0xAB);

  // Test with uint64_t value
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 1), 0xF0);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 2), 0xDE);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 3), 0xBC);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 4), 0x9A);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 5), 0x78);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 6), 0x56);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 7), 0x34);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0x123456789ABCDEF0, 8), 0x12);
}

TEST(BytesTest, EdgeCaseValues) {
  // Test with all bits set
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xFFFFFFFF, 1), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xFFFFFFFF, 2), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xFFFFFFFF, 3), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xFFFFFFFF, 4), 0xFF);

  // Test with all bits clear
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x00000000, 1), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x00000000, 2), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x00000000, 3), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x00000000, 4), 0x00);

  // Test with alternating bits 0xAAAAAAAA
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xAAAAAAAA, 1), 0xAA);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xAAAAAAAA, 2), 0xAA);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xAAAAAAAA, 3), 0xAA);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0xAAAAAAAA, 4), 0xAA);

  // Test with alternating bits 0x55555555
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x55555555, 1), 0x55);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x55555555, 2), 0x55);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x55555555, 3), 0x55);
  EXPECT_EQ(SeaDash::Bytes::getNthByte(0x55555555, 4), 0x55);
}

TEST(BytesTest, TypeLimitsAndOverflow) {
  // Test with maximum value for uint32_t
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(UINT32_MAX, 1), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(UINT32_MAX, 2), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(UINT32_MAX, 3), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(UINT32_MAX, 4), 0xFF);

  // Test with minimum value for uint32_t (all zeroes)
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(0, 1), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(0, 2), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(0, 3), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint32_t>(0, 4), 0x00);

  // Test with maximum value for uint64_t
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 1), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 2), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 3), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 4), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 5), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 6), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 7), 0xFF);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(UINT64_MAX, 8), 0xFF);

  // Test with minimum value for uint64_t (all zeroes)
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 1), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 2), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 3), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 4), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 5), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 6), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 7), 0x00);
  EXPECT_EQ(SeaDash::Bytes::getNthByte<uint64_t>(0, 8), 0x00);
}
