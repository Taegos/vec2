cmake_minimum_required(VERSION 3.6.2)
project(ComponentSystem VERSION 1.0.0)

enable_testing()

add_executable(
    ComponentSystemTest 
    component_system_test.cpp
)
target_include_directories(
    ComponentSystemTest 
    PUBLIC 
    ${CMAKE_SOURCE_DIR}
)
add_test(ComponentSystemTest ComponentSystemTest)