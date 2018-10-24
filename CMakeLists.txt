cmake_minimum_required (VERSION 3.10)
project (raytrace)

add_executable (raytrace main.cpp)

set (BUILD_GMOCK OFF)
set (INSTALL_GTEST OFF)

add_subdirectory (googletest)

enable_testing ()

add_executable (test_raytrace tests/tuple.cpp)
target_link_libraries (test_raytrace gtest gtest_main)
add_test (test_raytrace test_raytrace)
