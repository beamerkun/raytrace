cmake_minimum_required (VERSION 3.10)
project (raytrace)

include_directories (src)
add_executable (raytrace main.cpp
                         src/tuple.h
                         src/point.h
                         src/vector.h
)

set (BUILD_GMOCK OFF)
set (INSTALL_GTEST OFF)

add_subdirectory (googletest)

enable_testing ()

add_executable (test_raytrace tests/tuple.cpp
                              tests/point.cpp
                              tests/vector.cpp
)

target_link_libraries (test_raytrace gtest gtest_main)
add_test (test_raytrace test_raytrace)
