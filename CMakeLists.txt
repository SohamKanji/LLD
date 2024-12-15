cmake_minimum_required(VERSION 3.31)

project(LLD VERSION 1.00 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(app)

