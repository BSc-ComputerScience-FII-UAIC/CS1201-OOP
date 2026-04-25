# CMake minimum version required
cmake_minimum_required(VERSION 3.16)

# the name of the project
project(ex0)

# C++ minimum version required 
# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)

# add an executable target
add_executable(ex0_main main.cpp)

# fetch Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# add an executable test target
add_executable(
        ex0_test
        hello_test.cpp
)

# link the Google Test library
target_link_libraries(
        ex0_test
        gtest_main
)

# enable CMake's test runner to discover the tests included in the binary,
# using the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(ex0_test)
