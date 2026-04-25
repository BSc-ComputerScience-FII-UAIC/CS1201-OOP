# CMake minimum version required
cmake_minimum_required(VERSION 3.16)

# the name of the project
project(ex2_cmake)

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

