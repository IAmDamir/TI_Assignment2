cmake_minimum_required(VERSION 3.20)
project(TI_Assignment2)

set(CMAKE_CXX_STANDARD 20)

add_executable(TI_Assignment2 main.cpp
                NodesLoader/NodesLoader.h NodesLoader/Node.h NodesLoader/Node.cpp
                Step1/FileReader.h Step1/FileReader.cpp
                Step2/ShannonFanoDecoder.h Step2/ShannonFanoDecoder.cpp)
