cmake_minimum_required(VERSION 3.10)
project(passwordGenerator)

set(CMAKE_CXX_STANDARD 11)

add_executable(passwordGenerator src/main.cpp src/Generator.cpp src/Generator.h)