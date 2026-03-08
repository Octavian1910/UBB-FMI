#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#include "../../domain/medicament.h"


typedef struct {

} ValidatorMedicament;

/*
 * Valideaza un medicament.
 * Returneaza 0 dacă este valid.
 * Returnează un cod de eroare (ex: 1, 2, 3) dacă are date invalide.
 */
int valideazaMedicament(Medicament* m);

#endif