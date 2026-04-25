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