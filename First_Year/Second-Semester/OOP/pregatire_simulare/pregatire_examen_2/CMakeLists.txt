cmake_minimum_required(VERSION 4.1)
project(pregatire_examen_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(tests)

# AUTOMOC necesar pentru Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Caută Qt6 și modulul Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)



add_executable(pregatire_examen_2
        tests/Tests.cpp
        tests/Tests.h
        domain/Skirt.cpp
        domain/Skirt.h
        app_coordinator.cpp
        Repository/Repository.h
        Service/Service.h
        UI/UI.cpp
        UI/UI.h)


# Leagă Qt Widgets la proiect
target_link_libraries(pregatire_examen_2 PRIVATE Qt6::Widgets)