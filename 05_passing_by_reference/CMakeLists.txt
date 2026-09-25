cmake_minimum_required(VERSION 3.10)
project(ReferenceVariables LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(reference_variables src/main.cpp)

target_sources(reference_variables PRIVATE)