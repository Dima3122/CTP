cmake_minimum_required(VERSION 3.0)

project(project)
#set(CMAKE_CXX_CLANG_TIDY ${dir})
#set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.; -checks=*;)
add_subdirectory(external)
add_subdirectory(test)
add_subdirectory(src)
