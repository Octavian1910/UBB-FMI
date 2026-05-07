cmake_minimum_required(VERSION 3.26)
project(lab5_it1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5_it1
        app_coordinator.cpp
        tests/tests.cpp
        tests/tests.h
        domain/Medicine.cpp
        domain/Medicine.h
        domain/validator/ValidatorMedicine.cpp
        domain/validator/ValidatorMedicine.h
        domain/validator/ValidatorException.h
        repository/MedRepository.cpp
        repository/MedRepository.h
        repository/RepositoryException.h
        Service/MedService.cpp
        Service/MedService.h
        Service/ServiceException.h
        UI/UI.cpp
        UI/UI.h)
