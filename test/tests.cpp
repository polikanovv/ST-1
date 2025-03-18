// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(st1, sumPrime1) {
	uint64_t res = sumPrime(2000000);
	uint64_t expected = 142913828922;
	EXPECT_EQ(expected, res);
}
TEST(st1, sumPrime2) {
	uint64_t res = sumPrime(10);
	uint64_t expected = 17;
	EXPECT_EQ(expected, res);
}
TEST(CheckPrimeTest, BasicCases) {
	EXPECT_FALSE(checkPrime(0));
	EXPECT_FALSE(checkPrime(1));
	EXPECT_TRUE(checkPrime(2));
	EXPECT_TRUE(checkPrime(3));
	EXPECT_FALSE(checkPrime(4));
	EXPECT_TRUE(checkPrime(29));
	EXPECT_FALSE(checkPrime(30));
}
TEST(NPrimeTest, FirstFewPrimes) {
	EXPECT_EQ(nPrime(1), 2);
	EXPECT_EQ(nPrime(2), 3);
	EXPECT_EQ(nPrime(3), 5);
	EXPECT_EQ(nPrime(4), 7);
	EXPECT_EQ(nPrime(5), 11);
	EXPECT_EQ(nPrime(6), 13);
	EXPECT_EQ(nPrime(10), 29);
}
TEST(NextPrimeTest, SimpleCases) {
	EXPECT_EQ(nextPrime(2), 3);
	EXPECT_EQ(nextPrime(3), 5);
	EXPECT_EQ(nextPrime(4), 5);
	EXPECT_EQ(nextPrime(11), 13);
	EXPECT_EQ(nextPrime(17), 19);
	EXPECT_EQ(nextPrime(18), 19);
}
TEST(SumPrimeTest, SmallBoundaries) {
	EXPECT_EQ(sumPrime(10), 17);
	EXPECT_EQ(sumPrime(20), 77);
}
TEST(SumPrimeTest, ZeroAndOne) {
	EXPECT_EQ(sumPrime(0), 0);
	EXPECT_EQ(sumPrime(1), 0);
}
TEST(SumPrimeTest, LargeBound) {
	uint64_t res = sumPrime(2000000);
	uint64_t expected = 142913828922;
	EXPECT_EQ(res, expected);
}