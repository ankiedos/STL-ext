cmake_minimum_required(VERSION 3.16)
project(library-plus-plus)
set(LIBRARY_OUTPUT_PATH build/
set(CMAKE_CXX_STANDARD 2a)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -O3")

add_library(stdc++pp iostream_pp.hpp temp_lib.hpp)

include(FindGTest.cmake)
