cmake_minimum_required(VERSION 3.0)

project(project)
#set(CMAKE_CXX_CLANG_TIDY ${dir})
#set(CMAKE_CXX_CLANG_TIDY clang-tidy; -header-filter=.; -checks=*;)
add_custom_target(
        clang-format
        COMMAND /usr/bin/clang-format
        -style=file
        -i
        ${ALL_SOURCE_FILES}
)

add_custom_target(
        clang-tidy
        COMMAND /usr/bin/clang-tidy
        ${ALL_SOURCE_FILES}
        -config=''
        --
        -std=c++11
        ${INCLUDE_DIRECTORIES}
)
add_subdirectory(external)
add_subdirectory(test)
add_subdirectory(src)
