cmake_minimum_required(VERSION 3.16)
project(examples)

set(CMAKE_CXX_STANDARD 14)

add_executable(example0
        no-subtype.cpp)

add_executable(example1
        ret-cov.cpp)


add_executable(example2
        ret-cov2.cpp)

add_executable(example3
        arg-contrav.cpp)