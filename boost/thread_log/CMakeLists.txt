cmake_minimum_required(VERSION 3.7)

project(learn_thread_log)

set(CMAKE_CXX_STANDARD 11)	
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3")

include_directories("~normalhy/software/include")
link_directories("~normalhy/software/lib")

set(SRC_FILE
	${CMAKE_SOURCE_DIR}/log_manager/log_manager.cpp
	${CMAKE_SOURCE_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILE})
target_link_libraries(${PROJECT_NAME} dl pthread
	libboost_log.a
	libboost_log_setup.a
	libboost_system.a
	libboost_chrono.a
	libboost_thread.a
	libboost_program_options.a
	libboost_filesystem.a)
