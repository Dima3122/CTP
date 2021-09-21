cmake_minimum_required(VERSION 3.0)

project(project)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/gtest")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/cli11")
add_subdirectory(test)
add_subdirectory(src)
