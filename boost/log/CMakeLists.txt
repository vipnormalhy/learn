cmake_minimum_required(VERSION 3.7)

project(learn_log)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -DDEBUG")
set(CMAKE_DXX_FLAGS_RELEASE "-O3 -DNDEBUG")

include_directories("~/software/include")
link_directories("~/software/lib")

set(SRC_FILE
	${CMAKE_SOURCE_DIR}/learn_log.cpp)

set(BOOST_LIB_DIR "~/software/lib")
find_library(BOOST_LOG_LIB
	NAMES libboost_log.a
	PATHS ${BOOST_LIB_DIR})
find_library(BOOST_LOG_SETUP_LIB
	NAMES libboost_log_setup.a
	PATHS ${BOOST_LIB_DIR})
find_library(BOOST_SYSTEM_LIB
	NAMES libboost_system.a
	PATHS ${BOOST_LIB_DIR})
find_library(BOOST_FILESYSTEM_LIB
	NAMES libboost_filesystem.a
	PATHS ${BOOST_LIB_DIR})
find_library(BOOST_THREAD_LIB
	NAMES libboost_thread.a
	PATHS ${BOOST_LIB_DIR})

add_executable(${PROJECT_NAME} ${SRC_FILE})
target_link_libraries(${PROJECT_NAME} dl pthread
	${BOOST_LOG_LIB} ${BOOST_LOG_SETUP_LIB}
	${BOOST_SYSTEM_LIB}
	${BOOST_FILESYSTEM_LIB}
	${BOOST_THREAD_LIB}
	)

message(STATUS "find lib " ${BOOST_SYSTEM_LIB})
