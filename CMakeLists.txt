# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.17)
project(Stone)
include_directories(/ ast env exception stype parser)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -g
        #-Werror
        )

add_executable(Stone main.cpp Token.hpp exception/StoneException.h Lexer.h Lexer.cpp exception/ParseException.cpp exception/ParseException.h ast/AstTree.cpp ast/AstTree.h ast/AstNodeType.cpp ast/AstNodeType.h parser/BasicParser.cpp parser/BasicParser.h Parse.hpp stype/BasicType.h stype/BasicType.cpp env/Env.h env/BasicEnv.hpp parser/FuncParser.h parser/FuncParser.cpp env/NestEnv.hpp stype/Object.cpp stype/Object.h stype/Function.cpp stype/Function.h Naive.cpp Naive.h stype/NaiveFunction.cpp stype/NaiveFunction.h exception/StoneException.cpp parser/ClassParser.cpp parser/ClassParser.h stype/ClassInfo.h stype/StoneObject.cpp stype/StoneObject.h)