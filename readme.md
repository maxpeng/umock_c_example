# umock_c Example

This is an example about using [Azure/umock-c: A pure C mocking library](https://github.com/Azure/umock-c)
to mock C files for unit test.


## Prerequisites

1. [CMake](https://cmake.org/)
2. GNU C compiler


## Directory Structure

```
umock_c_example
├── CMakeLists.txt           --> main cmake configuration files
├── LICENSE
├── readme.md
├── src                      --> pythagorean example
│   ├── CMakeLists.txt
│   ├── main.c
│   ├── pythagorean.c
│   ├── pythagorean.h
│   ├── square_root.c        --> dependency of pythagorean.c
│   └── square_root.h
├── tests                    --> unit test against pythagorean.c
│   ├── CMakeLists.txt
│   └── pythagorean_ut       --> unit test by umock_c
└── testtools                --> unit test tools
    ├── CMakeLists.txt
    ├── ctest                --> ctest unit test library 
    ├── test_runner          --> test runner
    └── umock_c              --> azure umock_c mocking library
```
    
    
## References:

1. [Azure/umock-c: A pure C mocking library](https://github.com/Azure/umock-c/tree/master)
2. [Azure/azure-ctest: A simple portable C test runner](https://github.com/Azure/azure-ctest/tree/master)
3. [Azure/azure-c-testrunnerswitcher](https://github.com/Azure/azure-c-testrunnerswitcher/tree/master)
4. [CMake Tutorial - JohnLamp.netJohnLamp.net](https://www.johnlamp.net/cmake-tutorial.html)
5. [CMake Tutorial | CMake](https://cmake.org/cmake-tutorial/)
6. [Introduction to CMake by Example | derekmolloy.ie](http://derekmolloy.ie/hello-world-introductions-to-cmake/)


[![Build Status](https://travis-ci.org/maxpeng/umock_c_example.svg?branch=master)](https://travis-ci.org/maxpeng/umock_c_example)
