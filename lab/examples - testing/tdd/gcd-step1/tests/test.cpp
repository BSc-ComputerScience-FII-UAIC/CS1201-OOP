//
// Created by Dorel Lucanu on 4/29/21.
//
#include <gtest/gtest.h>
#include "../src/gcd.h"

TEST(GcdTest, Positive) {
EXPECT_EQ(4, gcd(8,12));
}