// Copyright 2023 Joshua Austill

#include <gtest/gtest.h>

#include <SeaDash.hpp>

// Demonstrate some basic assertions.
TEST(BitUtilsTest, getNBitsWorks) {
  uint8_t result = SeaDash::Bits::getNBits<uint8_t>(0b11100000, 5, 3);
  // Expect equality.
  EXPECT_EQ(result, 0b111);

  result = SeaDash::Bits::getNBits<uint8_t>(0b10101101, 2, 4);
  EXPECT_EQ(result, 0b1011);
}

TEST(BitUtilsTest, getNBitsHandlesOutOfBounds) {
  uint8_t result = SeaDash::Bits::getNBits<uint32_t>(0b1111, 999, 1);
  EXPECT_EQ(result, 0);

  result = SeaDash::Bits::getNBits<uint32_t>(0b1111, 0, 50000000);
  EXPECT_EQ(result, 0b1111);
}

TEST(BitUtilsTest, getNOnes) {
  uint32_t result = SeaDash::Bits::getNOnes<uint32_t>(4);

  EXPECT_EQ(result, 0b1111);

  uint64_t result64 = SeaDash::Bits::getNOnes<uint64_t>(63);
  EXPECT_EQ(result64,
            0b0111111111111111111111111111111111111111111111111111111111111111);
}

TEST(BitUtilsTest, getNOnesAt) {
  uint32_t result = SeaDash::Bits::getNOnesAt<uint32_t>(4, 4);

  EXPECT_EQ(result, 0b11110000);

  uint64_t result64 = SeaDash::Bits::getNOnesAt<uint64_t>(2, 63);
  EXPECT_EQ(
      result64,
      0b01000000000000000000000000000000000000000000000000000000000000000);
}

TEST(BitUtilsTest, setNBits) {
  uint32_t result = SeaDash::Bits::setNBitsAt<uint32_t>(0b0001, 0b11, 2, 2);

  EXPECT_EQ(result, 0b1101);

  uint64_t result64 = SeaDash::Bits::setNBitsAt<uint64_t>(0, 0b1111, 60, 4);
  EXPECT_EQ(
      result64,
      0b1111000000000000000000000000000000000000000000000000000000000000);
}

TEST(BitUtilsTest, setNBitsAtOutOfBounds) {
  uint32_t result =
      SeaDash::Bits::setNBitsAt<uint32_t>(0b01, 0b11111111, 999, 2);

  EXPECT_EQ(result, 0b01);
}

TEST(BitUtilsTest, setNBitsAtConstrainBits) {
  uint32_t result = SeaDash::Bits::setNBitsAt<uint32_t>(0b01, 0b111111, 1, 1);

  EXPECT_EQ(result, 0b11);
}

TEST(BitUtilsTest, getNBitsFullRange) {
  uint64_t value = ~0ULL;  // All bits set to 1
  uint64_t result = SeaDash::Bits::getNBits<uint64_t>(value, 0, 64);
  EXPECT_EQ(result, value);
}

TEST(BitUtilsTest, getNOnesFullRange) {
  uint32_t result = SeaDash::Bits::getNOnes<uint32_t>(32);
  EXPECT_EQ(result, ~0U);  // All bits set to 1
}

TEST(BitUtilsTest, setNBitsAtFullRange) {
  uint32_t result = SeaDash::Bits::setNBitsAt<uint32_t>(0, ~0U, 0, 32);
  EXPECT_EQ(result, ~0U);  // All bits set to 1
}

TEST(BitUtilsTest, getMaxN) {
  uint32_t result = SeaDash::Bits::getMaxN<uint32_t>();
  EXPECT_EQ(result, 32);
}

TEST(BitUtilsTest, getNBitsZero) {
  uint32_t result = SeaDash::Bits::getNBits<uint32_t>(0b1111, 0, 0);
  EXPECT_EQ(result, 0);  // Expect zero bits to be extracted
}

TEST(BitUtilsTest, setNBitsAtZero) {
  uint32_t result = SeaDash::Bits::setNBitsAt<uint32_t>(0b1111, 0b1111, 0, 0);
  EXPECT_EQ(result, 0b1111);  // No bits should be set
}

TEST(BitUtilsTest, getNBitsAtMaxOffset) {
  uint32_t result = SeaDash::Bits::getNBits<uint32_t>(0b10000000000000000000000000000001, 31, 1);
  EXPECT_EQ(result, 0b1);
}

TEST(BitUtilsTest, setNBitsAtMaxOffset) {
  uint32_t result = SeaDash::Bits::setNBitsAt<uint32_t>(0, 0b1, 31, 1);
  EXPECT_EQ(result, 0b10000000000000000000000000000000);
}

TEST(BitUtilsTest, setNBitsAtEdge) {
  uint32_t result = SeaDash::Bits::setNBitsAt<uint32_t>(0, 0b1, 31, 1);
  EXPECT_EQ(result, 0x80000000);  // Bit set at the most significant position

  uint32_t result2 = SeaDash::Bits::setNBitsAt<uint32_t>(0, 0b11, 30, 2);
  EXPECT_EQ(result2, 0xC0000000);  // Two bits set at the highest positions
}

TEST(BitUtilsTest, randomSetNBitsAt) {
  uint32_t value = 0b10101010101010101010101010101010;
  uint32_t bits = 0b1111;
  unsigned offset = 4;
  unsigned n = 4;

  uint32_t result = SeaDash::Bits::setNBitsAt<uint32_t>(value, bits, offset, n);
  EXPECT_EQ(result, 0b10101010101010101010101011111010);
}

TEST(BitUtilsTest, getNOnesAtBoundary) {
  uint32_t result = SeaDash::Bits::getNOnesAt<uint32_t>(31, 1);
  EXPECT_EQ(result, 0b11111111111111111111111111111110);
}

// Test cases for SeaDash::Bits::parity function
TEST(ParityTests, TestZero) {
    // Edge case: zero has even parity
    EXPECT_FALSE(SeaDash::Bits::parity(0));  // Expect even parity (false)
}

TEST(ParityTests, TestOne) {
    // Edge case: one has odd parity
    EXPECT_TRUE(SeaDash::Bits::parity(1));  // Expect odd parity (true)
}

TEST(ParityTests, TestTwo) {
    // Edge case: two has even parity
    EXPECT_TRUE(SeaDash::Bits::parity(2));  // Expect odd parity (true)
}

TEST(ParityTests, TestThree) {
    // 3 is 11 in binary, odd parity
    EXPECT_FALSE(SeaDash::Bits::parity(3));  // Expect even parity (false)
}

TEST(ParityTests, TestFour) {
    // 4 is 100 in binary, even parity
    EXPECT_TRUE(SeaDash::Bits::parity(4));  // Expect odd parity (true)
}

TEST(ParityTests, TestMaxUint8) {
    // 255 is 11111111 in binary, odd parity
    EXPECT_FALSE(SeaDash::Bits::parity(uint8_t(255)));  // Expect even parity (false)
}

TEST(ParityTests, TestMaxUint16) {
    // 65535 is 16 bits of 1, even parity
    EXPECT_FALSE(SeaDash::Bits::parity(uint16_t(65535)));  // Expect even parity (false)
}

TEST(ParityTests, TestMaxUint32) {
    // Edge case: max uint32_t (4294967295) has 32 ones, even parity
    EXPECT_FALSE(SeaDash::Bits::parity(uint32_t(4294967295U)));  // Expect even parity (false)
}

TEST(ParityTests, TestMaxUint64) {
    // Edge case: max uint64_t (all 64 bits set), even parity
    EXPECT_FALSE(SeaDash::Bits::parity(uint64_t(18446744073709551615ULL)));  // Expect even parity (false)
}

TEST(ParityTests, TestNegativeNumbers) {
    // Negative numbers will have many set bits due to 2's complement representation
    EXPECT_FALSE(SeaDash::Bits::parity(-1));  // odd
    EXPECT_TRUE(SeaDash::Bits::parity(-2));  // -2 in two's complement is all bits set except the last one, odd parity
    EXPECT_TRUE(SeaDash::Bits::parity(int8_t(-128))); // -128 in 8 bits is 10000000, odd parity
}

TEST(ParityTests, TestSingleBit) {
    // Test single bit numbers
    EXPECT_TRUE(SeaDash::Bits::parity(1));     // 00000001 -> odd parity
    EXPECT_TRUE(SeaDash::Bits::parity(2));    // 00000010 -> odd parity
    EXPECT_TRUE(SeaDash::Bits::parity(4));     // 00000100 -> odd parity
    EXPECT_TRUE(SeaDash::Bits::parity(128));   // 10000000 -> odd parity
}

TEST(ParityTests, TestMixedBits) {
    // Random mixed bit patterns
    EXPECT_FALSE(SeaDash::Bits::parity(0b1010101));    // 7-bit alternating, even parity
    EXPECT_FALSE(SeaDash::Bits::parity(0b10101010));  // 8-bit alternating, even parity
    EXPECT_FALSE(SeaDash::Bits::parity(0x55555555));  // 32-bit alternating, even parity
    EXPECT_FALSE(SeaDash::Bits::parity(0x5555555555555555ULL));  // 64-bit alternating, even parity
}
