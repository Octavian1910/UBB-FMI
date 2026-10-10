cmake_minimum_required(VERSION 4.1)
project(examen)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(domain)



add_executable(examen
        app_coordinator.cpp
        domain/Melodie.h
        domain/validator/ValidatorException.h
        domain/validator/ValidatorMelodie.cpp
        tests/tests.h
        tests/tests.cpp
        repository/MelodieRepository.h
        repository/MelodieRepository.cpp
        domain/Melodie.cpp
        repository/RepositoryException.h
        Service/ServiceException.h
        Service/MelodieService.h
        Service/MelodieService.cpp
        ui/GUI.h
        ui/MelodieTableModel.h)

target_link_libraries(examen PRIVATE Qt6::Widgets)