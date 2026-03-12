#include "validator.h"
#include <string.h>

int valideazaMedicament(Medicament* m)
{
    if (m->cod < 0) return 1; //cod invalid
    if (strlen(m->nume) == 0) return 2; //nume invalid
    if (m-> concentratie < 0) return 3; //concentratie invalida
    if (m-> cantitate < 0) return 4; //
    return 0; //Totul este corect


}