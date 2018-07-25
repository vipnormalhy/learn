cmake_minimum_required(VERSION 3.7)

project(learn_log)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -DDEBUG")
set(CMAKE_DXX_FLAGS_RELEASE "-O3 -DNDEBUG")

include_directories("~/software/include")
link_directories("~/software/lib")

set(SRC_FILE
	${CMAKE_SOURCE_DIR}/learn_log.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILE})
target_link_libraries(${PROJECT_NAME} 
	libboost_log.a libboost_system.a libboost_filesystem.a
	libboost_thread.a pthread dl
	boost_stacktrace_backtrace backtrace)
