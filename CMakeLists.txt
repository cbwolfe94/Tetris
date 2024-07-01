cmake_minimum_required(VERSION 3.20)

set(CURSES_LIBRARY      "/usr/lib/x86_64-linux-gnu/libncurses.so")
set(CURSES_INCLUDE_PATH "/usr/include/")
set(CMAKE_TOOLCHAIN_FILE toolchain/gcc.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(Curses REQUIRED)

# This makes intellisense a breeze
# Just set c_cpp_properties to use compileCommands
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(Tetris
    VERSION 1.0
    DESCRIPTION "Tetris"
    LANGUAGES C ASM)


# Specify the language standard
set(CMAKE_C_STANDARD 11)

set(APP_NAME        application)
set(APP_LIB_NAME    applicationLib)
set(APP_SOURCE_DIR  ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)