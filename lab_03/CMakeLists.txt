cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "-std=c++17")

project(lab_03)

set(HEADERS
    include/BubbleSort.h
    source/BubbleSort.hpp
    include/ShakerSort.h
    source/ShakerSort.hpp
    include/QSort.h
    source/QSort.hpp
    include/CoutVector.h
    source/CoutVector.hpp
)

set(SOURCE
    source/main.cc
)

add_executable(lab_03
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_03
    PUBLIC
        "include"
        "source"
)
