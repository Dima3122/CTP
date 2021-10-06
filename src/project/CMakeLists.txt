
add_executable(main project/main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
target_link_libraries(main lib)
target_link_libraries(main CLI11::CLI11)

set_compile_options(main)
