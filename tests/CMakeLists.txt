cmake_minimum_required(VERSION 3.6.2)
project(ComponentSystem VERSION 1.0.0)
enable_testing()
add_executable(
    Vec2Test 
    vec2_test.cpp
)
target_include_directories(
    Vec2Test 
    PUBLIC 
    ${CMAKE_SOURCE_DIR}
)
add_test(Vec2Test Vec2Test)