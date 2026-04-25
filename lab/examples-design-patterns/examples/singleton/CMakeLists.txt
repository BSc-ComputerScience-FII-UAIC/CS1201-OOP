cmake_minimum_required(VERSION 3.16)
project(singleton)

set(CMAKE_CXX_STANDARD 17)

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
add_executable(singleton_test v1/singleton_test.cpp)

# link the Google Test library
target_link_libraries(singleton_test gtest_main)

# add an executable test target
add_executable(singleton_dyn_test v2/singleton_dyn.h v2/singleton_dyn_test.cpp)

# link the Google Test library
target_link_libraries(singleton_dyn_test gtest_main)

# enable CMake's test runner to discover the tests included in the binary,
# using the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(singleton_test singleton_dyn_test)
