cmake_minimum_required(VERSION 3.26)
project(lab4___template)

set(CMAKE_CXX_STANDARD 14)

include_directories(domain)

add_executable(lab4___template
        domain/Medicine.cpp
        domain/Medicine.h
        domain/validator/ValidatorException.h
        domain/validator/MedValidator.cpp
        domain/validator/MedValidator.h
        repository/RepositoryException.h
        repository/MyVector.h
        repository/MedRepository.cpp
        repository/MedRepository.h
        service/MedService.cpp
        service/MedService.h
        tests/tests.cpp
        tests/tests.h
        main.cpp
        UI/ui.cpp
        UI/ui.h)
