cmake_minimum_required(VERSION 3.17)
project(PriorityQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(PriorityQueue PriorityQueue.c PriorityQueue.h PriorityQueueTest.c)