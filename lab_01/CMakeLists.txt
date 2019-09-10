cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project(lab_01)

set(HEADERS
    include/Lmatrix.h
    include/DLmatrix.h
    include/DLrecursive.h
    include/CoutVector.h
)

set(SOURCE 
    source/main.cc
    source/Lmatrix.cc
    source/DLmatrix.cc
    source/DLrecursive.cc
    source/CoutVector.cc
)

add_executable(lab_01
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_01
    PUBLIC
        "include"
)
