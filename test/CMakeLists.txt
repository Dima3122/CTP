cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.; -checks=*;)
add_executable(test test.cpp)
target_link_libraries(test PRIVATE lib)
target_link_libraries(
    test PRIVATE
    gtest gtest_main
)

