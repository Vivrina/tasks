cmake_minimum_required(VERSION 3.17)
project(tasks)

set(CMAKE_CXX_STANDARD 14)

add_executable(tasks main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")