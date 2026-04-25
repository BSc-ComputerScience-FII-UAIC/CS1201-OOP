//
// Created by Dorel Lucanu on 4/29/21.
//

#include "gtest/gtest.h"
#include "Date.h"

class DateTest : public testing::Test {
protected:  // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        d1_.setToday(2021, 5, 10);
        d2_.setToday(2020, 2, 28);
        d3_.setToday(2020, 12, 31);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    //
    // virtual void TearDown() {
    // }

    // Declares the variables your tests want to use.
    Date d1_, d2_, d3_;
};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests for the method today()
TEST_F(DateTest, Today) {
    ASSERT_STREQ("10.5.2021", d1_.today().c_str());
}

// Tests for the method tomorrow() .
TEST_F(DateTest, Tomorrow) {
    ASSERT_STREQ("11.5.2021", d1_.tomorrow().c_str());
}