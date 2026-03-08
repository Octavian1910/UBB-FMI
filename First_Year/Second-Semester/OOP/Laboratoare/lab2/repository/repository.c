#include "repository.h"
#include <stdlib.h>

RepoFarmacie* creeazaRepo()
{
    RepoFarmacie* v = malloc(sizeof(RepoFarmacie));
    v-> capacitate = 2;
    v-> lungime = 0;
    v-> elemente = malloc(sizeof(Medicament*) * v->capacitate);
    return v;
}

int actualizeaza_element_repo(RepoFarmacie* v,Medicament* m)
{
    Medicament* elem = cauta_medicament_repo(v,get_cod(m));
    if (elem == NULL)
       return -1;

    set_nume(elem,get_nume(m));
    set_concentratie(elem,get_concentratie(m));
    distrugeMedicament(m);
    return 0;
}

void resize(RepoFarmacie* v)
{
    int noua_capcaitate = 2 * v->capacitate;
    Medicament** elementeNoi = realloc(v->elemente,noua_capcaitate * sizeof(Medicament*));
    v->elemente = elementeNoi;
    v->capacitate = noua_capcaitate;
}

void adauga_repo(RepoFarmacie* v,Medicament* m)
{
    Medicament* elem = cauta_medicament_repo(v,get_cod(m));
    if (elem == NULL)
    {
        if (v->lungime == v->capacitate)
            resize(v);
        v->elemente[v->lungime] = m;
        v->lungime += 1;
    }
    else
    {
        set_cantitate(elem,get_cantitate(m));
    }
}

Medicament* cauta_medicament_repo(RepoFarmacie* v,int cod)
{
    for (int i = 0 ; i < v->lungime ; ++i)
    {
        if (v->elemente[i]->cod == cod)
        {
            return v->elemente[i];
        }
    }
    return NULL;
}

void distrugeRepo(RepoFarmacie* v)
{
    for (int i = 0; i < v->lungime ; i++)
    {
        distrugeMedicament(v->elemente[i]);
    }
    free(v->elemente);
    free(v);
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
