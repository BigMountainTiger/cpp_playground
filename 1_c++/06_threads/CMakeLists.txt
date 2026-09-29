cmake_minimum_required(VERSION 3.10)
project(Threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(std-1-threads-example src/main-1-std-threads-example.cpp)
target_sources(std-1-threads-example PRIVATE)

add_executable(std-2-threads-example src/main-2-std-jthreads-example.cpp)
target_sources(std-2-threads-example PRIVATE)

add_executable(std-3-std-condition-variable src/main-3-std-condition-variable.cpp)
target_sources(std-3-std-condition-variable PRIVATE)