cmake_minimum_required(VERSION 3.8)
project(umock_example)

set(CMAKE_C_STANDARD 99)

include (CTest)

set(SOURCE_FILES main.c pythagorean.c square_root.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${UMOCK_C_INC_DIR})
include_directories(${TEST_RUNNER_INC_DIR})
include_directories(${CTEST_INC_DIR})


add_executable(umock_example ${SOURCE_FILES})
