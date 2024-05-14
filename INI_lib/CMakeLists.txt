cmake_minimum_required(VERSION 3.27)
project(INI_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(INI_lib SHARED library.cpp library.h)