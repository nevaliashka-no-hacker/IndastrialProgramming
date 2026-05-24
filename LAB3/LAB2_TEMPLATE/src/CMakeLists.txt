cmake_minimum_required(VERSION 3.10)
project(myapp)

set(CMAKE_CXX_STANDARD 17)

add_executable(app main.cpp httplib.h)
target_include_directories(app PRIVATE .)

