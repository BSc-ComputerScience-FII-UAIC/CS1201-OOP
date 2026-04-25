# CMake minimum version required
cmake_minimum_required(VERSION 3.16)

# the name of the project
project(gcd_tdd)

# C++ minimum version required
set(CMAKE_CXX_STANDARD 14)

# add an executable target
add_executable(gcd_tdd_main src/main.cpp src/gcd.cpp src/gcd.h )

# for additional headers available for including from the sources of all targets
#include_directories(includes)

# fetch Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        #URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
        URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# add an executable test target
add_executable(gcd_tdd_test tests/test.cpp src/gcd.cpp)

# link the Google Test library
target_link_libraries(gcd_tdd_test gtest_main)

# enable CMake's test runner to discover the tests included in the binary,
# using the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(gcd_tdd_test)
