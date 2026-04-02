cmake_minimum_required(VERSION 3.26)

project(lab4 CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4
        main.cpp
        tests/tests.cpp
        domain/medicine.cpp
        domain/medicine.h
        Repository/MedRepository.cpp
        Repository/MedRepository.h
        Repository/RepositoryException.h
        Service/MedService.cpp
        Service/MedService.h
        domain/Validator/MedValidator.cpp
        domain/Validator/MedValidator.h
        domain/Validator/ValidatorException.h
        UI/UI.cpp
        UI/UI.h
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")