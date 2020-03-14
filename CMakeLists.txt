cmake_minimum_required(VERSION 3.5.0)
project(rbgcpp2py)

add_subdirectory(pybind11)

find_package(Threads)
find_package(Boost)
set(ENV{PYTHONPATH} ${PYTHON_PATH}:${CMAKE_CURRENT_BINARY_DIR})
find_package(Python3 COMPONENTS Interpreter Development)
if (${Python3_FOUND})
  pybind11_add_module(rbg_game bindings.cc rbg_game.cpp rbg_game.hpp ${Boost_LIBRARY_DIRS} ${Boost_INCLUDE_DIRS}) 
else()
  message("Install python3 development pacakge. (sudo apt install python3-deb)")
endif()
