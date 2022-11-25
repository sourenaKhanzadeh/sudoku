cmake_minimum_required(VERSION 3.0)

project(sudoku
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "Sudoku solver"
    )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INSTALL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/sudoku)

include_directories(${INCLUDE_DIR})

add_subdirectory(src)