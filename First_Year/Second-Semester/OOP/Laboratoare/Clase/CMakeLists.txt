cmake_minimum_required(VERSION 3.26)
project(clase)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)

add_executable(clase
        main.cpp
        domain/Pet.cpp
        domain/Pet.h
        repository/PetRepo.cpp
        repository/PetRepo.h
        tests/test.cpp
        tests/test.h
        service/PetStore.cpp
        service/PetStore.h
        UI/UI.cpp
        UI/UI.h)
