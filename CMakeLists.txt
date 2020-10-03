cmake_minimum_required(VERSION 3.16.3)

project(passwordGenerator)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} src/main.cpp src/Generator.cpp)