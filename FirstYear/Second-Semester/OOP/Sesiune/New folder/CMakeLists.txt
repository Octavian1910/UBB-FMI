cmake_minimum_required(VERSION 4.1)
project(melodii2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)



add_executable(melodii2)

target_link_libraries(melodii2 PRIVATE Qt6::Widgets)
