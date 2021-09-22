cmake_minimum_required(VERSION 3.0)

project(project)
set(CMAKE_CXX_CLANG_TIDY "")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gtest")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/cli11")
