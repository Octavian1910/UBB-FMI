cmake_minimum_required(VERSION 4.1)
project(furniture)

set(CMAKE_CXX_STANDARD 20)


# AUTOMOC necesar pentru Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Caută Qt6 și modulul Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)


include_directories(tests)




add_executable(furniture
        tests/Tests.cpp
        tests/Tests.h
        main.cpp
        Domain/Furniture.h
        Domain/Furniture.cpp
        Domain/Validator/Validator.cpp
        Repository/Repository.h
        Repository/Repository.cpp
        Service/Service.h
        Service/Service.cpp
        UI/UI.h
        UI/UI.cpp)


# Leagă Qt Widgets la proiect
target_link_libraries(furniture PRIVATE Qt6::Widgets)