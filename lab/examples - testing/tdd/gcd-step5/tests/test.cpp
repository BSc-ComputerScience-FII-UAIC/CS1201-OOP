//
// Created by Dorel Lucanu on 4/29/21.
//
#include <gtest/gtest.h>
#include "../src/gcd.h"

TEST(GcdTest, Positive) {
    EXPECT_EQ(4, gcd(8,12));
    EXPECT_EQ(7, gcd(28,21));
    EXPECT_EQ(1, gcd(23,31));
    EXPECT_EQ(1, gcd(48,17));
}

TEST(GcdTest, Trivial) {
    EXPECT_EQ(18, gcd(18,0));
    EXPECT_EQ(24, gcd(0,24));
    EXPECT_EQ(19, gcd(19,19));
    EXPECT_EQ(0, gcd(0,0));   // undefined
}

TEST(GcdTest, Negative) {
    EXPECT_EQ(6, gcd(18, -12));
    EXPECT_EQ(4, gcd(-28, 32));
    EXPECT_EQ(1, gcd(-29, -37));
}
