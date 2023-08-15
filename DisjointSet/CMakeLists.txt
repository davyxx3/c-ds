cmake_minimum_required(VERSION 3.17)
project(DisjointSet C)

set(CMAKE_C_STANDARD 99)

add_executable(DisjointSet DisjointSet.c DisjointSet.h DisjointSetTest.c)