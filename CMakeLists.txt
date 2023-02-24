cmake_minimum_required(VERSION 3.10)

project(
    PIDController
    VERSION 1.0
    LANGUAGES CXX
)

set(
    CMAKE_CXX_STANDARD 14
)

add_executable(PIDController main.cpp PIDController.cpp)