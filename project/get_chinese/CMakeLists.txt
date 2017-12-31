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

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
