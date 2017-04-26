cmake_minimum_required(VERSION 3.7)
project(word_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        LICENSE
        README.md src/word_list.c src/word_list.h)

add_executable(word_list ${SOURCE_FILES})