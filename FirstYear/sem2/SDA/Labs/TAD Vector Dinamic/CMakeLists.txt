cmake_minimum_required(VERSION 3.26)
project(TAD_Vector_Dinamic)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++")
include_directories(Teste)

add_executable(TAD_Vector_Dinamic
        "Proiect C++/App.cpp"
        "Proiect C++/IteratorVectorDinamic.cpp"
        "Proiect C++/IteratorVectorDinamic.h"
        "Proiect C++/VectorDinamic.cpp"
        "Proiect C++/VectorDinamic.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h)
