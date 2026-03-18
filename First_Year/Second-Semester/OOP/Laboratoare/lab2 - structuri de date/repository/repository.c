#include "repository.h"
#include <stdlib.h>

RepoFarmacie creeazaRepo()
{
    RepoFarmacie v;
    v.lungime = 0;
    return v;
}

int get_lungime_repo(RepoFarmacie* v) {
    return v->lungime;
}



int actualizeaza_element_repo(RepoFarmacie* v, Medicament m) {
    Medicament* elem = cauta_medicament_repo(v, get_cod(&m));
    if (elem == NULL) return -1;
    set_nume(elem, get_nume(&m));
    set_concentratie(elem, get_concentratie(&m));
    return 0;
}


void adauga_repo(RepoFarmacie* v, Medicament m) {  // Medicament, nu Medicament*
    Medicament* elem = cauta_medicament_repo(v, get_cod(&m));
    if (elem == NULL) {
        v->elemente[v->lungime] = m;
        v->lungime++;
    } else {
        set_cantitate(elem, get_cantitate(&m));
    }
}

Medicament* cauta_medicament_repo(RepoFarmacie* v,int cod)
{
    for (int i = 0 ; i < v->lungime ; ++i)
    {
        if (v->elemente[i].cod == cod)
        {
            return &v->elemente[i];
        }
    }
    return NULL;
}


int sterge_repo(RepoFarmacie* repo,int cod)
{
    Medicament* elem = cauta_medicament_repo(repo,cod);
    if (elem == NULL)
    {
        return -1;
    }
    set_cantitate(elem, 0);
    return 0;

}

int nr_medicamente_repo(RepoFarmacie* v)
{
    return v->lungime;
}


Medicament** get_all_repo(RepoFarmacie* v) {
    Medicament** lista = malloc(sizeof(Medicament*) * v->lungime);
    for (int i = 0; i < v->lungime; i++) {
        lista[i] = &v->elemente[i];
    }
    return lista;
}


