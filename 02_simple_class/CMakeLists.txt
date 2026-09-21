cmake_minimum_required(VERSION 3.10)
project(SimpleClass LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simple_class src/main.cpp)

target_sources(simple_class PRIVATE
    src/animals/amimal.cpp
    src/animals/dog.cpp
    src/animals/cat.cpp
)