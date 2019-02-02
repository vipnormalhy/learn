cmake_minimum_required(VERSION 3.7)

project(learn_traceback)

include_directories("~/software/include")
link_directories("~/software/lib")

set(SRC_FILES
	${CMAKE_SOURCE_DIR}/user_config.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -DBOOST_STACKTRACE_LINK -DBOOST_STACKTRACE_USE_BACKTRACE")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} 
	dl 
	pthread 
	backtrace
	boost_stacktrace_backtrace
	libboost_system.a 
	libboost_filesystem.a 
	libboost_thread.a 
	libboost_chrono.a)
