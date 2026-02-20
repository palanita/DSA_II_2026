cmake_minimum_required(VERSION 4.0)
project(Labor C)

set(CMAKE_C_STANDARD 23)

add_executable(Labor main.c
        function.h
        function.c)
