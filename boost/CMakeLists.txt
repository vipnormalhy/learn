cmake_minimum_required(VERSION 3.0.0)
project(find_public_dir VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("C:/Users/vipno/Downloads/boost_1_69_0")
link_directories("C:/Users/vipno/Downloads/boost_1_69_0/stage/lib")

set(SRC_FILES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/find_all_public_folder.cpp
)

add_executable(find_public_dir ${SRC_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
