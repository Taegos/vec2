cmake_minimum_required(VERSION 3.6.2)
project(Vec2Test VERSION 1.0.0)
enable_testing()
add_executable(
    Vec2Test 
    ${CMAKE_SOURCE_DIR}/vec2.cpp
    vec2_test.cpp
)
target_include_directories(
    Vec2Test 
    PUBLIC 
    ${CMAKE_SOURCE_DIR}
)
add_test(Vec2Test Vec2Test)
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake