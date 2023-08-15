cmake_minimum_required(VERSION 3.17)
project(Sort C)

set(CMAKE_C_STANDARD 99)

add_executable(Sort Sort.c Sort.h SortTest.c)