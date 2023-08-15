cmake_minimum_required(VERSION 3.17)
project(Queue C)

set(CMAKE_C_STANDARD 99)

add_executable(Queue Queue.c Queue.h QueueTest.c)