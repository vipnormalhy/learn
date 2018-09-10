cmake_minimum_required(VERSION 3.7)

project(learn_thread_log)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)	
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (APPLE)
	set(CMAKE_CXX_EXTENSIONS OFF)
endif (APPLE)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3")

set(BOOST_LIB_DIR "~/software/lib")
include_directories("~/software/include")
include_directories(${CMAKE_SOURCE_DIR})

set(SRC_FILE
	${CMAKE_SOURCE_DIR}/log_manager/log_manager.cpp
	${CMAKE_SOURCE_DIR}/main.cpp
	${CMAKE_SOURCE_DIR}/common.cpp

	${CMAKE_SOURCE_DIR}/network/server.cpp
	${CMAKE_SOURCE_DIR}/network/tcp_server.cpp
)

find_library(BOOST_LOG_LIB
	NAMES libboost_log.a
	PATHS ${BOOST_LIB_DIR}
	NO_DEFAULT_PATH)
	
find_library(BOOST_LOG_SETUP_LIB
	NAMES libboost_log_setup.a
	PATHS ${BOOST_LIB_DIR}
	NO_DEFAULT_PATH)
find_library(BOOST_SYSTEM_LIB
	NAMES libboost_system.a
	PATHS ${BOOST_LIB_DIR}
	NO_DEFAULT_PATH)
find_library(BOOST_FILESYSTEM_LIB
	NAMES libboost_filesystem.a
	PATHS ${BOOST_LIB_DIR}
	NO_DEFAULT_PATH)
find_library(BOOST_THREAD_LIB
	NAMES libboost_thread.a
	PATHS ${BOOST_LIB_DIR}
	NO_DEFAULT_PATH)
find_library(BOOST_CHRONO_LIB
	NAMES libboost_chrono.a
	PATHS ${BOOST_LIB_DIR}
	NO_DEFAULT_PATH)
find_library(BOOST_PROGRAM_OPTIONS_LIB
	NAMES libboost_program_options.a
	PATHS ${BOOST_LIB_DIR}
	NO_DEFAULT_PATH)

message(STATUS "find library ${BOOST_LOG_LIB}")

add_executable(${PROJECT_NAME} ${SRC_FILE})
target_link_libraries(${PROJECT_NAME}
	${BOOST_LOG_LIB}
	${BOOST_LOG_SETUP_LIB}
	${BOOST_SYSTEM_LIB}
	${BOOST_CHRONO_LIB}
	${BOOST_THREAD_LIB}
	${BOOST_PROGRAM_OPTIONS_LIB}
	${BOOST_FILESYSTEM_LIB}
	pthread)
