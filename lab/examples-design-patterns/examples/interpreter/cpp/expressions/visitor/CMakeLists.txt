cmake_minimum_required(VERSION 3.16)
project(visitor)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(visitor-eval)

add_executable(visitor-eval
        visitor-eval/demo.cpp
        visitor-eval/visitor-eval.cpp
        ast/ast-visitor.cpp
        parser/parser-visitor.cpp
        )
