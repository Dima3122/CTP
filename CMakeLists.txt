cmake_minimum_required(VERSION 3.0)
include(cmake/CompileOptions.cmake)

project(project)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(test)