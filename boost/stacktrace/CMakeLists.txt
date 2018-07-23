cmake_minimum_required(VERSION 3.7)

project(learn_traceback)

include_directories("~/software/include")
link_directories("~/software/lib")

set(SRC_FILES
	${CMAKE_SOURCE_DIR}/learn_stacktrace.cpp)

set(CMAKE_CXX_STANDARD 11)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} dl boost_stacktrace_backtrace boost_stacktrace_basic boost_stacktrace_noop boost_stacktrace_addr2line boost_system boost_chrono boost_thread)
