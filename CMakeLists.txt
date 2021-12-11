# cmake_minimum_required(VERSION <specify CMake version here>)
project(Stone)

set(CMAKE_CXX_STANDARD 11)

add_executable(Stone main.cpp Token.hpp StoneException.h Lexer.h Lexer.cpp ParseException.cpp ParseException.h)