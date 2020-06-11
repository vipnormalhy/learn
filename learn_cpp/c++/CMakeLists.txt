cmake_minimum_required(VERSION 3.7.0)

# project(test)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(SRC_FILE 
#     ${CMAKE_SOURCE_DIR}/learn_allocator.cpp
# )

# add_executable(${PROJECT_NAME} ${SRC_FILE})
# # target_compile_definitions(${PROJECT_NAME} PRIVATE CXX_STANDARD 11)
# set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)


# ------------------------ test for concurrency -----------------------------
project(concurrency)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_FILES
    ${CMAKE_SOURCE_DIR}/concurrency/helloworld.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)