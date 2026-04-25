//
// Created by Dorel Lucanu on 4/29/21.
//

#include "gtest/gtest.h"
#include "singleton.h"

class SingletonTest : public testing::Test {
protected:  // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        s2.setValue(9);
        // s3 = s1;  // compiling error
        s3.setValue(77);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    //
    // virtual void TearDown() {
    // }

    // Declares the variables your tests want to use.
    Singleton &s1 = Singleton::instance();
    Singleton &s2 = Singleton::instance();
    Singleton &s3 = s1;
    // Singleton s4 = s2;  // compiling error
};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

// Tests the uniqueness.
TEST_F(SingletonTest, Uniqueness) {
    ASSERT_EQ(s1.getValue(), s2.getValue());
    ASSERT_EQ(s1.getValue(), s3.getValue());
}

