cmake_minimum_required(VERSION 3.16)
project(parser_composite)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(parser_composite
        ast/ast-composite.cpp
        ast/ast-composite.h
        demo.cpp
        parser/parser-composite.cpp
        parser/parser-composite.h)
