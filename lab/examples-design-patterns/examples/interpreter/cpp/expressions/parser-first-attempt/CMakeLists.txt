cmake_minimum_required(VERSION 3.16)
project(parser_first_attempt)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(parser_first_attempt
        ast/ast.cpp
        ast/ast.h
        demo.cpp
        parser/parser.cpp
        parser/parser.h)
