add_executable(main project/main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../external/cli11/include/CLI)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../lib/lib)
target_link_libraries(main lib)
target_link_libraries(main CLI11::CLI11)

set_compile_options(main)
