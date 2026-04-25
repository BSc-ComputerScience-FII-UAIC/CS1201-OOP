# CMake minimum version required
cmake_minimum_required(VERSION 3.16)

# the name of the project
project(ex1_cmake)

# C++ minimum version required
set(CMAKE_CXX_STANDARD 14)

# add an executable target
add_executable(ex1_main src/main.cpp)
add_executable(ex1_fnctns src/main.cpp src/fnctns.cpp)

# for additional headers available for including from the sources of all targets
include_directories(includes)

# add a library target
add_library(ex1_library STATIC src/fnctns.cpp)

# linking the library
find_library(EX1_LIBRARY ex1_library lib)
target_link_libraries(ex1_main LINK_PUBLIC ${EX1_LIBRARY})
