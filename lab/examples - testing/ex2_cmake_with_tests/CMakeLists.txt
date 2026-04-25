# CMake minimum version required
cmake_minimum_required(VERSION 3.16)

# the name of the project
project(ex2_cmake_with_tests)

# C++ minimum version required
set(CMAKE_CXX_STANDARD 14)

# add an executable target
add_executable(ex2_main src/main.cpp)
add_executable(ex2_date src/main.cpp src/Date.cpp)

# for additional headers available for including from the sources of all targets
include_directories(includes)

# add a library target
add_library(ex2_library STATIC src/Date.cpp)

# linking the library
find_library(EX2_LIBRARY ex2_library lib)
target_link_libraries(ex2_main LINK_PUBLIC ${EX2_LIBRARY})


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
add_executable(ex2_test1 tests/DateTest.cpp src/Date.cpp)

# link the Google Test library
target_link_libraries(ex2_test1 gtest_main)

# enable CMake's test runner to discover the tests included in the binary,
# using the GoogleTest CMake module
include(GoogleTest)
gtest_discover_tests(ex2_test1)

