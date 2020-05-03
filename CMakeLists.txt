# CMakeList.txt : CMake project for simple-computer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("simple-computer")

# Add source to this project's executable.
add_executable (simple-computer "simple-computer.cpp" "simple-computer.h" "Lexer.cpp" "Lexer.h" "Token.h" )

# TODO: Add tests and install targets if needed.
