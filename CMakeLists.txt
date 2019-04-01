cmake_minimum_required(VERSION 3.6.2)
project(Vec2 VERSION 1.0.0)
add_subdirectory(tests)
add_library(Vec2 STATIC vec2.cpp vec2.h)