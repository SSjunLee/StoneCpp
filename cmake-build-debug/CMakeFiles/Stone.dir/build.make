# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\cpp\Stone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\cpp\Stone\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Stone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stone.dir/flags.make

CMakeFiles/Stone.dir/main.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/main.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Stone.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\main.cpp.obj -c D:\code\cpp\Stone\main.cpp

CMakeFiles/Stone.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\main.cpp > CMakeFiles\Stone.dir\main.cpp.i

CMakeFiles/Stone.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\main.cpp -o CMakeFiles\Stone.dir\main.cpp.s

CMakeFiles/Stone.dir/Lexer.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/Lexer.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/Lexer.cpp.obj: ../Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Stone.dir/Lexer.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\Lexer.cpp.obj -c D:\code\cpp\Stone\Lexer.cpp

CMakeFiles/Stone.dir/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/Lexer.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\Lexer.cpp > CMakeFiles\Stone.dir\Lexer.cpp.i

CMakeFiles/Stone.dir/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/Lexer.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\Lexer.cpp -o CMakeFiles\Stone.dir\Lexer.cpp.s

CMakeFiles/Stone.dir/exception/ParseException.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/exception/ParseException.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/exception/ParseException.cpp.obj: ../exception/ParseException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Stone.dir/exception/ParseException.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\exception\ParseException.cpp.obj -c D:\code\cpp\Stone\exception\ParseException.cpp

CMakeFiles/Stone.dir/exception/ParseException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/exception/ParseException.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\exception\ParseException.cpp > CMakeFiles\Stone.dir\exception\ParseException.cpp.i

CMakeFiles/Stone.dir/exception/ParseException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/exception/ParseException.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\exception\ParseException.cpp -o CMakeFiles\Stone.dir\exception\ParseException.cpp.s

CMakeFiles/Stone.dir/ast/AstTree.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/ast/AstTree.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/ast/AstTree.cpp.obj: ../ast/AstTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Stone.dir/ast/AstTree.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\ast\AstTree.cpp.obj -c D:\code\cpp\Stone\ast\AstTree.cpp

CMakeFiles/Stone.dir/ast/AstTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/ast/AstTree.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\ast\AstTree.cpp > CMakeFiles\Stone.dir\ast\AstTree.cpp.i

CMakeFiles/Stone.dir/ast/AstTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/ast/AstTree.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\ast\AstTree.cpp -o CMakeFiles\Stone.dir\ast\AstTree.cpp.s

CMakeFiles/Stone.dir/ast/AstNodeType.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/ast/AstNodeType.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/ast/AstNodeType.cpp.obj: ../ast/AstNodeType.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Stone.dir/ast/AstNodeType.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\ast\AstNodeType.cpp.obj -c D:\code\cpp\Stone\ast\AstNodeType.cpp

CMakeFiles/Stone.dir/ast/AstNodeType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/ast/AstNodeType.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\ast\AstNodeType.cpp > CMakeFiles\Stone.dir\ast\AstNodeType.cpp.i

CMakeFiles/Stone.dir/ast/AstNodeType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/ast/AstNodeType.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\ast\AstNodeType.cpp -o CMakeFiles\Stone.dir\ast\AstNodeType.cpp.s

CMakeFiles/Stone.dir/parser/BasicParser.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/parser/BasicParser.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/parser/BasicParser.cpp.obj: ../parser/BasicParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Stone.dir/parser/BasicParser.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\parser\BasicParser.cpp.obj -c D:\code\cpp\Stone\parser\BasicParser.cpp

CMakeFiles/Stone.dir/parser/BasicParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/parser/BasicParser.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\parser\BasicParser.cpp > CMakeFiles\Stone.dir\parser\BasicParser.cpp.i

CMakeFiles/Stone.dir/parser/BasicParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/parser/BasicParser.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\parser\BasicParser.cpp -o CMakeFiles\Stone.dir\parser\BasicParser.cpp.s

CMakeFiles/Stone.dir/stype/BasicType.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/stype/BasicType.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/stype/BasicType.cpp.obj: ../stype/BasicType.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Stone.dir/stype/BasicType.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\stype\BasicType.cpp.obj -c D:\code\cpp\Stone\stype\BasicType.cpp

CMakeFiles/Stone.dir/stype/BasicType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/stype/BasicType.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\stype\BasicType.cpp > CMakeFiles\Stone.dir\stype\BasicType.cpp.i

CMakeFiles/Stone.dir/stype/BasicType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/stype/BasicType.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\stype\BasicType.cpp -o CMakeFiles\Stone.dir\stype\BasicType.cpp.s

CMakeFiles/Stone.dir/parser/FuncParser.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/parser/FuncParser.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/parser/FuncParser.cpp.obj: ../parser/FuncParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Stone.dir/parser/FuncParser.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\parser\FuncParser.cpp.obj -c D:\code\cpp\Stone\parser\FuncParser.cpp

CMakeFiles/Stone.dir/parser/FuncParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/parser/FuncParser.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\parser\FuncParser.cpp > CMakeFiles\Stone.dir\parser\FuncParser.cpp.i

CMakeFiles/Stone.dir/parser/FuncParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/parser/FuncParser.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\parser\FuncParser.cpp -o CMakeFiles\Stone.dir\parser\FuncParser.cpp.s

CMakeFiles/Stone.dir/stype/Object.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/stype/Object.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/stype/Object.cpp.obj: ../stype/Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Stone.dir/stype/Object.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\stype\Object.cpp.obj -c D:\code\cpp\Stone\stype\Object.cpp

CMakeFiles/Stone.dir/stype/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/stype/Object.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\stype\Object.cpp > CMakeFiles\Stone.dir\stype\Object.cpp.i

CMakeFiles/Stone.dir/stype/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/stype/Object.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\stype\Object.cpp -o CMakeFiles\Stone.dir\stype\Object.cpp.s

CMakeFiles/Stone.dir/stype/Function.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/stype/Function.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/stype/Function.cpp.obj: ../stype/Function.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Stone.dir/stype/Function.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\stype\Function.cpp.obj -c D:\code\cpp\Stone\stype\Function.cpp

CMakeFiles/Stone.dir/stype/Function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/stype/Function.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\stype\Function.cpp > CMakeFiles\Stone.dir\stype\Function.cpp.i

CMakeFiles/Stone.dir/stype/Function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/stype/Function.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\stype\Function.cpp -o CMakeFiles\Stone.dir\stype\Function.cpp.s

CMakeFiles/Stone.dir/Naive.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/Naive.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/Naive.cpp.obj: ../Naive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Stone.dir/Naive.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\Naive.cpp.obj -c D:\code\cpp\Stone\Naive.cpp

CMakeFiles/Stone.dir/Naive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/Naive.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\Naive.cpp > CMakeFiles\Stone.dir\Naive.cpp.i

CMakeFiles/Stone.dir/Naive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/Naive.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\Naive.cpp -o CMakeFiles\Stone.dir\Naive.cpp.s

CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.obj: ../stype/NaiveFunction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\stype\NaiveFunction.cpp.obj -c D:\code\cpp\Stone\stype\NaiveFunction.cpp

CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\stype\NaiveFunction.cpp > CMakeFiles\Stone.dir\stype\NaiveFunction.cpp.i

CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\stype\NaiveFunction.cpp -o CMakeFiles\Stone.dir\stype\NaiveFunction.cpp.s

CMakeFiles/Stone.dir/exception/StoneException.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/exception/StoneException.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/exception/StoneException.cpp.obj: ../exception/StoneException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Stone.dir/exception/StoneException.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\exception\StoneException.cpp.obj -c D:\code\cpp\Stone\exception\StoneException.cpp

CMakeFiles/Stone.dir/exception/StoneException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/exception/StoneException.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\exception\StoneException.cpp > CMakeFiles\Stone.dir\exception\StoneException.cpp.i

CMakeFiles/Stone.dir/exception/StoneException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/exception/StoneException.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\exception\StoneException.cpp -o CMakeFiles\Stone.dir\exception\StoneException.cpp.s

CMakeFiles/Stone.dir/parser/ClassParser.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/parser/ClassParser.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/parser/ClassParser.cpp.obj: ../parser/ClassParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Stone.dir/parser/ClassParser.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\parser\ClassParser.cpp.obj -c D:\code\cpp\Stone\parser\ClassParser.cpp

CMakeFiles/Stone.dir/parser/ClassParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/parser/ClassParser.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\parser\ClassParser.cpp > CMakeFiles\Stone.dir\parser\ClassParser.cpp.i

CMakeFiles/Stone.dir/parser/ClassParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/parser/ClassParser.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\parser\ClassParser.cpp -o CMakeFiles\Stone.dir\parser\ClassParser.cpp.s

CMakeFiles/Stone.dir/stype/StoneObject.cpp.obj: CMakeFiles/Stone.dir/flags.make
CMakeFiles/Stone.dir/stype/StoneObject.cpp.obj: CMakeFiles/Stone.dir/includes_CXX.rsp
CMakeFiles/Stone.dir/stype/StoneObject.cpp.obj: ../stype/StoneObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Stone.dir/stype/StoneObject.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Stone.dir\stype\StoneObject.cpp.obj -c D:\code\cpp\Stone\stype\StoneObject.cpp

CMakeFiles/Stone.dir/stype/StoneObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stone.dir/stype/StoneObject.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\cpp\Stone\stype\StoneObject.cpp > CMakeFiles\Stone.dir\stype\StoneObject.cpp.i

CMakeFiles/Stone.dir/stype/StoneObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stone.dir/stype/StoneObject.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\cpp\Stone\stype\StoneObject.cpp -o CMakeFiles\Stone.dir\stype\StoneObject.cpp.s

# Object files for target Stone
Stone_OBJECTS = \
"CMakeFiles/Stone.dir/main.cpp.obj" \
"CMakeFiles/Stone.dir/Lexer.cpp.obj" \
"CMakeFiles/Stone.dir/exception/ParseException.cpp.obj" \
"CMakeFiles/Stone.dir/ast/AstTree.cpp.obj" \
"CMakeFiles/Stone.dir/ast/AstNodeType.cpp.obj" \
"CMakeFiles/Stone.dir/parser/BasicParser.cpp.obj" \
"CMakeFiles/Stone.dir/stype/BasicType.cpp.obj" \
"CMakeFiles/Stone.dir/parser/FuncParser.cpp.obj" \
"CMakeFiles/Stone.dir/stype/Object.cpp.obj" \
"CMakeFiles/Stone.dir/stype/Function.cpp.obj" \
"CMakeFiles/Stone.dir/Naive.cpp.obj" \
"CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.obj" \
"CMakeFiles/Stone.dir/exception/StoneException.cpp.obj" \
"CMakeFiles/Stone.dir/parser/ClassParser.cpp.obj" \
"CMakeFiles/Stone.dir/stype/StoneObject.cpp.obj"

# External object files for target Stone
Stone_EXTERNAL_OBJECTS =

Stone.exe: CMakeFiles/Stone.dir/main.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/Lexer.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/exception/ParseException.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/ast/AstTree.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/ast/AstNodeType.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/parser/BasicParser.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/stype/BasicType.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/parser/FuncParser.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/stype/Object.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/stype/Function.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/Naive.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/stype/NaiveFunction.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/exception/StoneException.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/parser/ClassParser.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/stype/StoneObject.cpp.obj
Stone.exe: CMakeFiles/Stone.dir/build.make
Stone.exe: CMakeFiles/Stone.dir/linklibs.rsp
Stone.exe: CMakeFiles/Stone.dir/objects1.rsp
Stone.exe: CMakeFiles/Stone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\cpp\Stone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable Stone.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Stone.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stone.dir/build: Stone.exe

.PHONY : CMakeFiles/Stone.dir/build

CMakeFiles/Stone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Stone.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Stone.dir/clean

CMakeFiles/Stone.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\cpp\Stone D:\code\cpp\Stone D:\code\cpp\Stone\cmake-build-debug D:\code\cpp\Stone\cmake-build-debug D:\code\cpp\Stone\cmake-build-debug\CMakeFiles\Stone.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Stone.dir/depend

