cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_FLAGS "-std=c++17")

project(lab_07)

set(HEADERS
    include/KnuthMorrisPratt.h
    include/BoilerMyr.h
)

set(SOURCE
    source/main.cc
    source/KnuthMorrisPratt.cc
    source/BoilerMyr.cc
)

add_executable(lab_07
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_07
    PUBLIC
        "include"
)
