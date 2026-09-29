cmake_minimum_required(VERSION 4.3)
project(LagrangePolynom)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_CXX_STANDARD 20)

add_executable(LagrangePolynom main.cpp
        Point.h
        LagrangeInterpolation.cpp
        LagrangeInterpolation.h)
