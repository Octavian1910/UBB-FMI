#pragma once
#include "../domain/Melodie.h"

class ValidatorMelodie
{
public:
    /*
     * Metoda valideaza o melodie
     * pre : param melodie de tip Melodie pe care trb sa o validam
     * post : -
     * arunca : ValidatorException daca melodia are probleme , un camp nu se respecta
     * Erorile apar pt :
     *  - id negativ
     *  - titlu vid
     *  - artist vid
     *  - rank care nu se afla intre 0 si 10
     */
    static void validate(const Melodie& melodie);
};

