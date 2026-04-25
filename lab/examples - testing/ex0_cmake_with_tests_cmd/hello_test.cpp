#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
EXPECT_STRNE("mine", "yours");
// Expect equality.
EXPECT_EQ(2 + 2, 4);
}