cmake_minimum_required(VERSION 2.8.11)

project(umock_c_example2)
include(CTest)

option(use_ctest "set USE_CTEST to ON to use CTest." ON)
option(use_cppunittest "set CPP_UNITTEST to ON to use cppunittest" OFF)

add_subdirectory(testtools)
add_subdirectory(tests)
add_subdirectory(src)
