cmake_minimum_required(VERSION 3.10.0)
project(rbgcpp2py)

# Build in release by default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pipe -Ofast")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -march=native")

add_subdirectory(pybind11)

find_package(Threads)
find_package(Boost)
set(ENV{PYTHONPATH} ${PYTHON_PATH}:${CMAKE_CURRENT_BINARY_DIR})
find_package(Python3 COMPONENTS Interpreter Development)
pybind11_add_module(rbg_game bindings.cc rbg_game.cpp rbg_game.hpp ${Boost_LIBRARY_DIRS} ${Boost_INCLUDE_DIRS}) 
