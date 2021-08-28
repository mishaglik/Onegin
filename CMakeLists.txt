cmake_minimum_required(VERSION 3.19)
project(Onegin)

set(CMAKE_CXX_STANDARD 14)

set(COMMON_SOURCES fileLib.cpp main.cpp text.cpp text.h)
set(SORTER_SOURCES oneginSorterLib.cpp)
set(MIXER_SOURCES oneginMixerLib.cpp oneginMixerLib.h)
#set(TEST_SOURCES  run_tests.cpp test_file1.cpp test_file2.cpp)

add_executable(OneginSorter ${COMMON_SOURCES} ${SORTER_SOURCES})
add_executable(OneginMixer ${COMMON_SOURCES} ${MIXER_SOURCES})