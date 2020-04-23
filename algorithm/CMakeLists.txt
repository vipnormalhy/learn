# cmake for learn algorithm

cmake_minimum_required(VERSION 3.14.0)

project(LearnAlgorithm)

set(CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_FILES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/BlackRedTree/brt.h
    ${CMAKE_SOURCE_DIR}/NQueen.cpp
    )

add_executable(${PROJECT_NAME} ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)