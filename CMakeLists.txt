cmake_minimum_required(VERSION 3.26)
project(CS402_SP_LAB2 C)

set(CMAKE_C_STANDARD 11)

add_executable(CS402_SP_LAB2 main.c
        employee.h
        employee.c
        readfile.h
        readfile.c)
