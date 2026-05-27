cmake_minimum_required(VERSION 4.1)
project(simulare_oop)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(simulare_oop
        main.cpp
        tests/Tests.h
        tests/Tests.cpp
        Domain/Postare.h
        Domain/Postare.cpp
        Repository/Repository.h
        Repository/Repository.cpp
        Service/Service.h
        Service/Service.cpp
        UI/UI.h
        UI/UI.h
        UI/UI.cpp)


target_link_libraries(simulare_oop PRIVATE Qt6::Widgets)
