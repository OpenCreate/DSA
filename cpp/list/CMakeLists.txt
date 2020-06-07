cmake_minimum_required(VERSION 3.16)
project(list)

set(CMAKE_CXX_STANDARD 17)

add_executable(list main.cc SingleList.h DoubleList.h)