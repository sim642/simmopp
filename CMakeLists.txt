cmake_minimum_required(VERSION 3.3)
project(simmopp)

#set(CMAKE_CXX_COMPILER clang)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")

include_directories(include)

set(SOURCE_FILES src/main3.cpp)
add_executable(simmopp ${SOURCE_FILES})

set(TEST_FILES test/test1.cpp test/main.cpp)
add_executable(simmopp-test ${TEST_FILES})
target_link_libraries(simmopp-test gtest gtest_main)