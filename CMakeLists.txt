cmake_minimum_required(VERSION 3.10)

project(
    PIDController
    VERSION 1.0
    LANGUAGES CXX
)

# Change according to convenience:
list(APPEND CMAKE_PREFIX_PATH "/home/whizbuzzer/vcpkg/packages/matplotplusplus_x64-linux/share/matplot++")
find_package(Matplot++ REQUIRED)

set(
    CMAKE_CXX_STANDARD 14
)

if (Matplot++_FOUND)
    add_executable(PIDController src/main.cpp)
    target_link_libraries(PIDController PUBLIC Matplot++::matplot)
    target_include_directories(PIDController PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)    
endif ()