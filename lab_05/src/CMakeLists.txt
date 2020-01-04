cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "-std=c++17")

project(lab_05)

set(HEADERS
    include/Multiplication.h
    include/Conveyor.h
)

set(SOURCE 
    source/main.cc
    source/Multiplication.cc
    source/Conveyor.cc
)

add_executable(lab_05
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_05
    PUBLIC
        "include"
)
