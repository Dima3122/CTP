cmake_minimum_required(VERSION 3.0)

add_executable(main project/main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
target_link_libraries(main lib)