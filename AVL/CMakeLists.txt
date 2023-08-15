cmake_minimum_required(VERSION 3.17)
project(AVL C)

set(CMAKE_C_STANDARD 99)

add_executable(AVL AVL.c AVL.h AVLTest.c)