cmake_minimum_required(VERSION 3.28)
project(advent_of_code_2015 C)

set(CMAKE_C_STANDARD 11)

add_library(helperFunct helperFunct.c helperFunct.h)
target_include_directories(helperFunct PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(day-1)