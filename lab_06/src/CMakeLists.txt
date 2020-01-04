cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "-std=c++17")

project(lab_06)

set(HEADERS
    include/Matrix.h
    include/FullSearch.h
    include/AntSearch.h
)

set(SOURCE
    source/main.cc
    include/Matrix.hpp
    source/FullSearch.cc
    source/AntSearch.cc
)

add_executable(lab_06
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_06
    PUBLIC
        "include"
)
