cmake_minimum_required(VERSION 4.1)
project(radation)

set(CMAKE_CXX_STANDARD 20)

# AUTOMOC necesar pentru Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Caută Qt6 și modulul Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(radation main.cpp
        tests/Tests.cpp
        tests/Tests.h
        Domain/Radiation.cpp
        Domain/Radiation.h
        Domain/Validator/Validator.h
        Domain/Validator/ValidatorException.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        UI/UI.cpp
        UI/UI.h)


# Leagă Qt Widgets la proiect
target_link_libraries(radation Qt6::Widgets)

if (WIN32)
    add_custom_command(TARGET radation POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_RUNTIME_DLLS:radation>"
            "$<TARGET_FILE_DIR:radation>"
            COMMAND_EXPAND_LISTS
    )

    add_custom_command(TARGET radation POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:radation>/platforms"
    )

    add_custom_command(TARGET radation POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${Qt6_DIR}/../../../plugins/platforms/qwindows.dll"
            "$<TARGET_FILE_DIR:radation>/platforms/qwindows.dll"
    )
endif()