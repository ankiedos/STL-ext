cmake_minimum_required(VERSION 3.20)
project(library-plus-plus)
set(LIBRARY_OUTPUT_PATH build/)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -O3")

add_library(stdc++pp STATIC iostream_pp.hpp temp_lib.hpp)

include(FindGTest.cmake)
