cmake_minimum_required (VERSION 2.8)
project (rang)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(include)
set(CATCH_HEADER_PATH ${PROJECT_SOURCE_DIR}/test/catch.hpp)

add_executable(vTest ${PROJECT_SOURCE_DIR}/test/visualTest.cpp)
add_executable(runTest ${PROJECT_SOURCE_DIR}/test/test.cpp ${CATCH_HEADER_PATH})
