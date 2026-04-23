cmake_minimum_required(VERSION 4.1)
project(Het9 C)

set(CMAKE_C_STANDARD 23)

add_executable(Het9 main.c
        functions.h
        functions.c)
