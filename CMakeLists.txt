cmake_minimum_required(VERSION 3.19)
project(Regex_stream)

set(CMAKE_CXX_STANDARD 14)

add_executable(Regex_stream main.cpp Node.cpp Node.h Scanner.cpp Scanner.h Parser.cpp Parser.h Generator.cpp Generator.h)