cmake_minimum_required(VERSION 3.23)
project(laba3rkpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(laba3rkpp main.cpp Component.h Tipper.cpp Truck.cpp TrailerTruck.cpp Van.cpp Trucks.cpp Primitives.h Composite.h Composite.cpp Truck.cpp)
