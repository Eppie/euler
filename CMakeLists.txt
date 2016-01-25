cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++14 -g -Ofast)

file(GLOB_RECURSE source [0-3]/*.cpp main.cpp helper.cpp)

add_executable(euler ${source})

