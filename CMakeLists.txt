cmake_minimum_required(VERSION 3.21)
project(GPS_CLion)

set(CMAKE_CXX_STANDARD 11)

include_directories(cpp
        gpsFunctions.cpp)

add_executable(GPS-RouteCalculator-FitSDK
        main.cpp)

