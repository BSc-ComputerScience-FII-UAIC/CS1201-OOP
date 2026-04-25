//
// Created by Dorel Lucanu on 4/28/21.
//

#include <gtest/gtest.h>
#include "../includes/fnctns.h"
#include <climits>

// Tests for inc2
TEST(Ex1Test, BasicAssertionsInc2) {
    EXPECT_EQ(5, inc2(3));
    ASSERT_TRUE(inc2(7) > 7);
}

// Tests for sqr
TEST(Ex1Test, BasicAssertionsSqr) {
    EXPECT_EQ(9, sqr(3));
    ASSERT_TRUE(sqr(-5) > 0);
}

// Tests for combinations of the two
TEST(Ex1Test, CombinedAssertions) {
    EXPECT_EQ(inc2(2), sqr(2));
    ASSERT_TRUE(sqr(7) > inc2(7));
    ASSERT_TRUE(inc2(1) > sqr(1));
}

// Tests for boundary cases
TEST(Ex1Test, BondaryAssertions) {
    ASSERT_TRUE(inc2(INT_MAX) > INT_MAX);
    ASSERT_TRUE(sqr(INT_MAX/5) > INT_MAX/5);
}