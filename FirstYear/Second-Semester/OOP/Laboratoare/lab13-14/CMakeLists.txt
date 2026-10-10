cmake_minimum_required(VERSION 3.26)

project(lab5_it1)

set(CMAKE_CXX_STANDARD 17)

# AUTOMOC necesar pentru Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Caută Qt6 și modulul Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)

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

        Service/Undo/UndoAction.h
        UI/GUI.cpp
        UI/GUI.h
        Service/Observer.h
        UI/RecipeTableModel.h
        UI/RecipeCRUDGUI.h
        UI/RecipeReadOnlyGUI.h
)

# Leagă Qt Widgets la proiect
target_link_libraries(lab5_it1 PRIVATE Qt6::Widgets)