cmake_minimum_required(VERSION 2.8.11)

set(TEST_RUNNER_C_FILES
    ${CMAKE_CURRENT_LIST_DIR}/src/testmutex.c
)

set(TEST_RUNNER_H_FILES
    ${CMAKE_CURRENT_LIST_DIR}/src/macro_utils.h
    ${CMAKE_CURRENT_LIST_DIR}/src/testmutex.h
    ${CMAKE_CURRENT_LIST_DIR}/src/testrunnerswitcher.h
)

add_library(testrunnerswitcher
    ${TEST_RUNNER_C_FILES} ${TESTRUNNER_H_FILES})

# this is the include directory
# the following "set" statetement exports across the project a global variable called
# TEST_RUNNER_INC_DIR that expands to whatever needs to included when using "test_runner" library
set(TEST_RUNNER_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/src CACHE INTERNAL "this is what needs to be included if using test_runner lib" FORCE)
