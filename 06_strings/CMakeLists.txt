cmake_minimum_required(VERSION 3.10)
project(Strings LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(strings src/main.cpp)

target_sources(strings PRIVATE)