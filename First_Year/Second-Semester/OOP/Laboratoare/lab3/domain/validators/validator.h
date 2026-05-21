#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#include "../../domain/medicament.h"


typedef struct {
    int dummy;
} ValidatorMedicament;

/*
 Valideaza un medicament

 :param m: pointer la medicament

 :return:
 0 daca medicamentul este valid
 1 daca codul este invalid
 2 daca numele este invalid
 3 daca concentratia este invalida
 4 daca cantitatea este invalida

 :pre:
 m != NULL

 :post:
 se verifica validitatea campurilor medicamentului si se returneaza o val potrivita
*/
int valideazaMedicament(Medicament* m);

#endif