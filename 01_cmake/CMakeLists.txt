cmake_minimum_required(VERSION 3.10)
project(HelloWorld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world src/main.cpp)

target_sources(hello_world PRIVATE
    src/what_to_say.cpp
)