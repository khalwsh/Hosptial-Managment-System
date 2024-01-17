cmake_minimum_required(VERSION 3.24)
project(Hosptial_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Hosptial_System main.cpp Person.h Person.cpp Disease.h Disease.cpp Available.h Available.cpp Patient.h Patient.cpp Doctor.cpp Doctor.h)
