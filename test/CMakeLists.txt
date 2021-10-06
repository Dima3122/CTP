cmake_minimum_required(VERSION 3.0)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE lib)
target_link_libraries(
    test PRIVATE
    gtest gtest_main
)
add_custom_target(check ALL COMMAND test)
set_compile_options(test)
