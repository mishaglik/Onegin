cmake_minimum_required(VERSION 3.19)
project(Onegin)

set(CMAKE_CXX_STANDARD 14)

set(COMMON_SOURCES fileLib.cpp main.cpp text.cpp text.h)
set(SORTER_SOURCES oneginSorterLib.cpp)

add_executable(OneginSorter ${COMMON_SOURCES} ${SORTER_SOURCES})
