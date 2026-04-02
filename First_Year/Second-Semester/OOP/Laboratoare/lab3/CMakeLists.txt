cmake_minimum_required(VERSION 3.16)
project(untitled3 C)

set(CMAKE_C_STANDARD 11)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Werror -Wextra)
endif()

add_executable(untitled3
        domain/domain.c
        teste/teste.c
        main/main.c
        service/service.c
        repository/repository.c
        repository/repository.h
        lista/MyList.c
        lista/MyList.h
        ui/ui.c
        ui/ui.h
)