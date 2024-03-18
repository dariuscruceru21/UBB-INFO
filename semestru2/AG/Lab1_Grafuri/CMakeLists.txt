cmake_minimum_required(VERSION 3.27)
project(Lab1_Grafuri)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab1_Grafuri
        app.cpp
        Graph.cpp
        Graph.h
            )
