cmake_minimum_required(VERSION 3.7.0)

project(plugin_test)

set(SRC_FILES
	${CMAKE_SOURCE_DIR}/plugin_base.cpp)

set(SO_SRC_FILES
	${CMAKE_SOURCE_DIR}/plugin_test_so.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Werror -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3")

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} dl)

add_library("${PROJECT_NAME}_so" SHARED ${SO_SRC_FILES})
