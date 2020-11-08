cmake_minimum_required(VERSION 3.16)
project(ch_05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ch_05
    main.cpp
    Vehicle.cpp
    Vehicle.h
    VehicleSurrogate.cpp
    VehicleSurrogate.h)
