cmake_minimum_required(VERSION 3.19.6)
project(library-plus-plus)
set(PROJECT_BINARY_DIR build/)
set(PROJECT_SOURCE_DIR .)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
set(BINARY_OUTPUT_PATH build/)
set(EXECUTABLE_OUTPUT_PATH ${LIBRARY_OUTPUT_PATH})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -O3")
enable_language(CXX)
set(TEST_FILES "tests/temp_lib_ut.cpp"
               "tests/iostream_pp_ut.cpp")

#add_subdirectory(includes)
#add_subdirectory(includes/containers)
set(CONTAINERS "includes/containers/Char.hpp")

#add_subdirectory(includes/math)
set(MATH "includes/math/Equations.hpp")

#add_subdirectory(tests)

include(FindGTest.cmake)
add_library(stdc++pp STATIC iostream_pp.hpp
                            temp_lib.hpp
                            ${CONTAINERS}
                            ${MATH}
                            defs.hpp)
set_target_properties(stdc++pp PROPERTIES LINKER_LANGUAGE CXX)
add_executable(lib++_ut maintest.cpp ${TEST_FILES})
target_link_libraries(lib++_ut ${GTEST_MAIN_LIBRARY}
                               ${GTEST_LIBRARY}
                               ${GMOCK_MAIN_LIBRARY}
                               ${GMOCK_LIBRARY}
                               stdc++pp.a)
