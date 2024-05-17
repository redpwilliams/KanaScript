cmake_minimum_required(VERSION 3.26)
project(KanaScript)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)  # Replace with your actual path


add_executable(KanaScript main.cpp
        Token.hpp
        Token.cpp
        Lexer.cpp
        Lexer.hpp
        Util.cpp)