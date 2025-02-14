cmake_minimum_required(VERSION 3.23)
project(laba4rkpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(laba4rkpp main.cpp Truck.cpp Truck.h Van.cpp Van.h Tipper.cpp Tipper.h TrailerTruck.cpp TrailerTruck.h Composite.cpp Composite.h)
