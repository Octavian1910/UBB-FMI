cmake_minimum_required(VERSION 3.26)
project(Cursuri)

set(CMAKE_CXX_STANDARD 14)


include_directories("Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C")
include_directories("Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C++")
include_directories("Curs3 - Containere (Matrice, Colectie, Multime, Dictionar, Coada)/Implementare Colectie - reprezentare secventiala folosind vector dinamic")
include_directories("Curs4 - Liste inlantuite - alocare dinamica/Implementare Colectie - reprezentare simplu inlantuita folosind alocare dinamica")

add_executable(Cursuri

        "Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C/main.c"
        "Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C/VectorDinamic.c"
        "Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C/VectorDinamic.h"
        "Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C++/main.cpp"
        "Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C++/VectorDinamic.cpp"
        "Curs2 - Containere si iteratori, Tablou, Vector Dinamic%20/VectorDinamic - implementare/C++/VectorDinamic.h"
        "Curs3 - Containere (Matrice, Colectie, Multime, Dictionar, Coada)/Implementare Colectie - reprezentare secventiala folosind vector dinamic/Colectie.cpp"
        "Curs3 - Containere (Matrice, Colectie, Multime, Dictionar, Coada)/Implementare Colectie - reprezentare secventiala folosind vector dinamic/Colectie.h"
        "Curs3 - Containere (Matrice, Colectie, Multime, Dictionar, Coada)/Implementare Colectie - reprezentare secventiala folosind vector dinamic/main.cpp"
        "Curs4 - Liste inlantuite - alocare dinamica/Implementare Colectie - reprezentare simplu inlantuita folosind alocare dinamica/colectie.cpp"
        "Curs4 - Liste inlantuite - alocare dinamica/Implementare Colectie - reprezentare simplu inlantuita folosind alocare dinamica/colectie.h"
        "Curs4 - Liste inlantuite - alocare dinamica/Implementare Colectie - reprezentare simplu inlantuita folosind alocare dinamica/main.cpp"
        )
