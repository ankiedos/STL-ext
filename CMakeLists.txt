cmake_minimum_required(VERSION 3.20)
project(library-plus-plus)
set(LIBRARY_OUTPUT_PATH build/)
set(BINARY_OUTPUT_PATH build/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -O3")
set(TEST_FILES "temp_lib_ut.cpp"
               "iostream_pp_ut.cpp")

include(FindGTest.cmake)
add_library(stdc++pp STATIC iostream_pp.hpp temp_lib.hpp)

add_executable(lib++_ut maintest.cpp ${TEST_FILES})
target_link_libraries(lib++_ut ${GTEST_MAIN_LIBRARY}
                               ${GTEST_LIBRARY}
                               ${GMOCK_MAIN_LIBRARY}
                               ${GMOCK_LIBRARY}
                               stdc++pp)
