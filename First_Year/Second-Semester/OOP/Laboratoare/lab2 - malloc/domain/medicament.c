#include "medicament.h"
#include <stdlib.h>
#include <string.h>

Medicament* creeazaMedicament(int cod,char* nume, int concentratie,int cantitate)
{
    Medicament *m = malloc(sizeof(Medicament));
    m->cod = cod;
    m->nume = malloc(strlen(nume) + 1);
    strcpy(m->nume,nume);

    m->concentratie = concentratie;
    m->cantitate = cantitate;
    return m;
}

//gettere
int get_cod(Medicament* m)
{
    return m->cod;
}

int get_concentratie(Medicament* m)
{
    return m->concentratie;
}
int get_cantitate(Medicament* m)
{
    return m->cantitate;
}
char* get_nume(Medicament* m)
{
    return m->nume;
}

//settere
void set_cod(Medicament* m,int cod_nou)
{
    m->cod = cod_nou;
}
void set_concentratie(Medicament* m,int concentratie_noua)
{
    m->concentratie = concentratie_noua;
}
void set_cantitate(Medicament* m,int cantitate_noua)
{
    m->cantitate = cantitate_noua;
}
void set_nume(Medicament* m,char* nume_nou)
{
    free(m->nume);
    m->nume = malloc(strlen(nume_nou) + 1);
    strcpy(m->nume,nume_nou);

}



void distrugeMedicament(Medicament *m)
{
    free(m->nume);
    free(m);
}

