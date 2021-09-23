cmake_minimum_required(VERSION 3.0)

project(project)
set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.; -checks=*;)
add_subdirectory(lib)
add_subdirectory(project)
