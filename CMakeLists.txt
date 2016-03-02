cmake_minimum_required(VERSION 3.3)
project(simmopp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(include)

set(SOURCE_FILES src/main.cpp)
add_executable(simmopp ${SOURCE_FILES})