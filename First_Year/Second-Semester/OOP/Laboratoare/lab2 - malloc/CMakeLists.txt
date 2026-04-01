cmake_minimum_required(VERSION 3.26)

project(lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab2
        domain/medicament.c
        tests/teste.c
        main.c
        tests/teste.h
        repository/repository.c
        service/service.c
        service/service.h
        domain/validators/validator.c
        domain/validators/validator.h
        UI/ui.c
        UI/ui.h
)