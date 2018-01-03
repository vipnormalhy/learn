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

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG -O0")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} boost_system boost_filesystem pthread boost_thread boost_regex boost_program_options)
