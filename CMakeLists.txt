cmake_minimum_required(VERSION 3.0)

project(project)
#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;--extra-arg-before=-std=c++17;${CLANG_TIDY_ARGS}")
add_subdirectory(external)
add_subdirectory(test)
add_subdirectory(src)
