cmake_minimum_required(VERSION 3.27)
project(Farmacie C)

set(CMAKE_C_STANDARD 11)

add_executable(Farmacie
        main.c

        domain/medicament.c
        domain/validators/validator.c

        repository/repository.c
        service/service.c

        ui/ui.c

        tests/teste.c
        service/service.c
)