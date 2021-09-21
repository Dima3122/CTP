cmake_minimum_required(VERSION 3.0)

project(Library)

add_library(lib STATIC lib/foo.cpp)
set_target_properties(lib PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)