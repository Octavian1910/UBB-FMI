#ifndef REPO_H_
#define REPO_H_
#include "../domain/medicament.h"

typedef struct
{
    Medicament** elemente;
    int lungime;
    int capacitate;
}RepoFarmacie;

RepoFarmacie* creeazaRepo();
void distrugeRepo(RepoFarmacie* v);
void adauga_repo(RepoFarmacie* v,Medicament* m);
int sterge_repo(RepoFarmacie* v,int cod);
Medicament* cauta_medicament_repo(RepoFarmacie* v,int cod);
int nr_medicamente_repo(RepoFarmacie* v);
int actualizeaza_element_repo(RepoFarmacie* v,Medicament* m);

#endif