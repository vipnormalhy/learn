cmake_minimum_required(VERSION 3.7)

project(simple_test)

include_directories("~normalhy/software/include")
link_directories("~normalhy/software/lib")

set(CMAKE_CXX_STANDARD 11)

set(SRC_FILE
	${CMAKE_SOURCE_DIR}/text_archive_test.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILE})
target_link_libraries(${PROJECT_NAME} libboost_serialization.a)

set(SRC_FILE2
	${CMAKE_SOURCE_DIR}/binary_archive_test.cpp)

add_executable(${PROJECT_NAME}2 ${SRC_FILE2})
target_link_libraries(${PROJECT_NAME}2 libboost_serialization.a)
