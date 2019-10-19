cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "-std=c++17")

project(lab_02)

set(HEADERS
    include/Matrix.h
    include/DefaultMultiplication.h
    include/VinogradMultiplication.h
    include/ModifiedVinogradMultiplication.h
)

set(SOURCE 
    source/main.cc
    source/Matrix.cc
    source/DefaultMultiplication.cc
    source/VinogradMultiplication.cc
    source/ModifiedVinogradMultiplication.cc
)

add_executable(lab_02
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_02
    PUBLIC
        "include"
)
