cmake_minimum_required(VERSION 3.17)
project(Graph C)

set(CMAKE_C_STANDARD 99)

add_executable(Graph GraphTest.c ListGraph.c ListGraph.h Queue.h Queue.c)