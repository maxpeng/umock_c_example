cmake_minimum_required(VERSION 2.8.11)

set(UMOCK_C_C_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umock_c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umock_c_negative_tests.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockalloc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockcall.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockcallrecorder.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypename.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_bool.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_stdint.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_charptr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockcallpairs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockstring.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockautoignoreargs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umock_log.c
    )

set(UMOCK_C_H_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umock_c.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umock_c_internal.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umock_c_negative_tests.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockalloc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockcall.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockcallrecorder.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypename.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_bool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_c.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_stdint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umocktypes_charptr.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockcallpairs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockstring.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umockautoignoreargs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/umock_log.h
    )

# build umock_c as a library.
add_library(umock_c
    ${UMOCK_C_C_FILES} ${UMOCK_C_H_FILES})

# this is the include directory of umokc_c
# the following "set" statetement exports across the project a global variable called
# UMOCK_C_INC_FOLDER that expands to whatever needs to included when using "umock_c" library.
set(UMOCK_C_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/src CACHE INTERNAL "this is what needs to be included if using umock_c lib" FORCE)
