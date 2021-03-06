cmake_minimum_required(VERSION 3.7.0)
project(get_chinese)

# boost directory
# need boost filesystem, regex, python
if (NOT DEFINED LOCAL_BOOST_DIRECTORY)
  message(FATAL_ERROR "Cannot find LOCAL_BOOST_DIRECTORY")
endif(NOT DEFINED LOCAL_BOOST_DIRECTORY)


set(SOURCE_FILES
  get_chinese.cpp)

# include directoies
include_directories(${LOCAL_BOOST_DIRECTORY}/include)
# library directories
link_directories(${LOCAL_BOOST_DIRECTORY}/lib)

message(STATUS "boost local directory is " ${LOCAL_BOOST_DIRECTORY})

# find static library
find_library(BOOST_SYSTEM_LIB
  NAMES libboost_system.a
  PATHS ${LOCAL_BOOST_DIRECTORY}/lib)
find_library(BOOST_FILESYSTEM_LIB
  NAMES libboost_filesystem.a
  PATHS ${LOCAL_BOOST_DIRECTORY}/lib)
find_library(BOOST_THREAD_LIB
  NAMES libboost_thread.a
  PATHS ${LOCAL_BOOST_DIRECTORY}/lib)
find_library(BOOST_REGEX_LIB
  NAMES libboost_regex.a
  PATHS ${LOCAL_BOOST_DIRECTORY}/lib)
find_library(BOOST_PROGRAM_OPTIONS_LIB
  NAMES libboost_program_options.a
  PATHS ${LOCAL_BOOST_DIRECTORY}/lib)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG -O0")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${BOOST_SYSTEM_LIB} ${BOOST_FILESYSTEM_LIB} pthread ${BOOST_THREAD_LIB} ${BOOST_REGEX_LIB} ${BOOST_PROGRAM_OPTIONS_LIB})
