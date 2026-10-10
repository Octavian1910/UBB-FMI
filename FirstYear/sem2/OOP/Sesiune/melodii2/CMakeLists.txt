cmake_minimum_required(VERSION 4.1)
project(melodii2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(domain)

add_executable(melodii2
        domain/Melodie.h
        domain/Melodie.cpp
        domain/validator/Validator.h
        domain/validator/Validator.cpp
        domain/validator/ValidatorException.h
        repository/Repo.h
        repository/RepoException.h
        repository/Repo.cpp
        service/ServiceException.h
        service/Service.h
        service/Service.cpp
        tests/Tests.h
        tests/Tests.cpp
        app_coordinator.cpp
        ui/MyTableModel.h
        ui/GUI.h)

target_link_libraries(melodii2 PRIVATE Qt6::Widgets)