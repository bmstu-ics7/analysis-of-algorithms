cmake_minimum_required(VERSION 3.1.0)

project(lab_01)

set_target_properties(${TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

set(HEADERS
    include/Lmatrix.h
    include/DLmatrix.h
    include/DLrecursive.h
)

set(SOURCE 
    source/main.cc
    source/Lmatrix.cc
    source/DLmatrix.cc
    source/DLrecursive.cc
)

add_executable(lab_01
    ${HEADERS}
    ${SOURCE}
)

target_include_directories(lab_01
    PUBLIC
        "include"
)
