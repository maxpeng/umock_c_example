cmake_minimum_required(VERSION 3.8)

option(use_ctest "set USE_CTEST to ON to use CTest." ON)
option(use_cppunittest "set CPP_UNITTEST to ON to use cppunittest" OFF)


if(use_ctest)
    add_definitions(-DUSE_CTEST)
elseif(use_cppunittest)
    add_definitions(-DCPP_UNITTEST)
else()
    message(FATAL_ERROR "You need to select either \"use_ctest\" or \"use_cppunittest\" option.")
endif()

#add_definitions(-DENABLE_MOCKS)

set(umock_c_c_files
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umock_c.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umock_c_negative_tests.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockalloc.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockcall.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockcallrecorder.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypename.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_bool.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_c.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_stdint.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_charptr.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockcallpairs.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockstring.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockautoignoreargs.c
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umock_log.c
    )

set(umock_c_h_files
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umock_c.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umock_c_internal.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umock_c_negative_tests.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockalloc.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockcall.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockcallrecorder.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypename.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_bool.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_c.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_stdint.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umocktypes_charptr.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockcallpairs.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockstring.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umockautoignoreargs.h
    ${PROJECT_SOURCE_DIR}/testtools/umock_c/src/umock_log.h
    )

include_directories(${CTEST_INC_DIR})
include_directories(${TEST_RUNNER_INC_DIR})
include_directories(${UMOCK_C_INC_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCE_FILES
    pythagorean_ut.c
    main.c ${PROJECT_SOURCE_DIR}/src/pythagorean.c
    ${PROJECT_SOURCE_DIR}/testtools/ctest/src/ctest.c
    ${PROJECT_SOURCE_DIR}/testtools/test_runner/src/testmutex.c
    ${umock_c_c_files})

#add_executable(${CMAKE_CURRENT_BINARY_DIR}/pythagorean_ut ${SOURCE_FILES})
add_executable(pythagorean_ut ${SOURCE_FILES})

add_test(pythagarean_test pythagorean_ut)