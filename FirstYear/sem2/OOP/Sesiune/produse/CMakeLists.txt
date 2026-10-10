cmake_minimum_required(VERSION 4.1)
project(produse)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(domain)



add_executable(produse
        domain/Produs.cpp
        tests/Tests.h
        tests/Tests.cpp
        app_coordinator.cpp
        domain/validator/ValidatorException.h
        domain/validator/Validator.h
        domain/validator/Validator.cpp
        repository/RepositoryException.h
        repository/Repository.h
        repository/Repository.cpp
        service/Service.h
        service/Service.cpp
        service/ServiceException.h
        ui/PordusTableModel.h
        ui/GUI.h)

target_link_libraries(produse PRIVATE Qt6::Widgets)