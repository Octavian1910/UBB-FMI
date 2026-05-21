cmake_minimum_required(VERSION 4.1)
project(simulare_ex_masina)

set(CMAKE_CXX_STANDARD 20)

include_directories(tests)


# AUTOMOC necesar pentru Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Caută Qt6 și modulul Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(simulare_ex_masina
        tests/Tests.cpp
        tests/Tests.h
        app_coordinator.cpp
        domain/Car.cpp
        domain/Car.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        UI/UI.cpp
        UI/UI.h)


# Leagă Qt Widgets la proiect
target_link_libraries(simulare_ex_masina PRIVATE Qt6::Widgets)