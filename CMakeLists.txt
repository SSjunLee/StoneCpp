# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.17)
project(Stone)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -g
        #-Werror
        )

add_executable(Stone main.cpp Token.hpp StoneException.h Lexer.h Lexer.cpp ParseException.cpp ParseException.h ast/AstTree.cpp ast/AstTree.h ast/AstNodeType.cpp ast/AstNodeType.h BasicParser.cpp BasicParser.h Parse.hpp stype/BasicType.h stype/BasicType.cpp Env.h BasicEnv.hpp FuncParser.h FuncParser.cpp NestEnv.hpp stype/Object.cpp stype/Object.h stype/Function.cpp stype/Function.h)