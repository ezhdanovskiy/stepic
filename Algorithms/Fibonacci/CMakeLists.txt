cmake_minimum_required(VERSION 3.5)
project(Fibonacci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Fibonacci main.cpp)