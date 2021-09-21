cmake_minimum_required(VERSION 3.0)

project(project)
set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.; -checks=*;)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/gtest")
add_subdirectory(test)
add_subdirectory(src)
