cmake_minimum_required(VERSION 2.8.11)

set(CTEST_C_FILES
    ${CMAKE_CURRENT_LIST_DIR}/src/ctest.c
)

set(CTEST_H_FILES
    ${CMAKE_CURRENT_LIST_DIR}/src/ctest.h
    ${CMAKE_CURRENT_LIST_DIR}/src/ctest_macros.h
)


add_library(ctest
    ${CTEST_C_FILES} ${CTEST_H_FILES})

# this is the include directory
# the following "set" statetement exports across the project a global variable called
# CTEST_INC_DIR that expands to whatever needs to included when using "ctest" library
set(CTEST_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/src CACHE INTERNAL "this is what needs to be included if using test_runner lib" FORCE)
