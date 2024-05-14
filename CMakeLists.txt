cmake_minimum_required(VERSION 3.27)
project(INI_parser)
include_directories(INI_lib)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_executable(INI_parser main.cpp)

add_subdirectory(INI_lib)
target_link_libraries(INI_parser INI_lib)
