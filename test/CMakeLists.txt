cmake_minimum_required(VERSION 3.0)

add_executable(test test.cpp)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/gtest/googletest/include/gtest)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/lib/lib)
target_link_libraries(test PRIVATE lib)
target_link_libraries(
    test PRIVATE
    gtest gtest_main
)
add_custom_target(check ALL COMMAND test)
set_compile_options(test)