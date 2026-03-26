cmake_minimum_required(VERSION 4.1)
project(labor C)

set(CMAKE_C_STANDARD 23)

add_executable(labor main.c
        functions.c
        functions.h)
