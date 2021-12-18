add_executable(main project/main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Statement/)
target_link_libraries(main Statements)
set_compile_options(main)