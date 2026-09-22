cmake_minimum_required(VERSION 3.10)
project(SmartPointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(smart_pointer src/main.cpp)

target_sources(smart_pointer PRIVATE)