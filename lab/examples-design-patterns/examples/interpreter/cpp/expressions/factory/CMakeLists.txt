cmake_minimum_required(VERSION 3.16)
project(factory)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(factory
        ast/ast-factory.cpp
        demo.cpp
        parser/parser-factory.cpp
        visitors/visitor.h)
