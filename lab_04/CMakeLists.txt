cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "-std=c++17")

project(lab_04)

set(HEADERS
    include/Matrix.h
    include/ThreadMultiplication.h
)

set(SOURCE 
    source/main.cc
    source/Matrix.cc
    source/ThreadMultiplication.cc
)

add_executable(lab_04
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_04
    PUBLIC
        "include"
)
