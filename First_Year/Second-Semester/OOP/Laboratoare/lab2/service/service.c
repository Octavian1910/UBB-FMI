#include "service.h"
#include <stdlib.h>


ServiceFarmacie* creeaza_service_farmacie(RepoFarmacie *Repo,ValidatorMedicament* Validator)
{
    ServiceFarmacie* s = malloc(sizeof(ServiceFarmacie));
    s->repo = Repo;
    s->validator = Validator;
    return s;
}

Medicament* cauta_medicament_service(ServiceFarmacie* s,int cod)
{
    return cauta_medicament_repo(s->repo,cod);
}

void distruge_service_farmacie(ServiceFarmacie *s)
{
    distrugeRepo(s->repo);
    free(s);
}

int nr_medicamente_service(ServiceFarmacie *s)
{
    return nr_medicamente_repo(s->repo);
}

int adaugaService(ServiceFarmacie* s,int cod,char* nume,int concentratie,int cantitate)
{
    Medicament *medicament = creeazaMedicament(cod,nume,concentratie,cantitate);
    int erori = valideazaMedicament(medicament);
    if (erori)
    {
        return erori;
    }
    adauga_repo(s->repo,medicament);
    return 0;
}

int actualizeazaService(ServiceFarmacie *s,int cod,char* nume,int concentratie)
{
    Medicament* m = creeazaMedicament(cod,nume,concentratie,1);
    int erori = valideazaMedicament(m);
    if (erori == 0)
    {
        return actualizeaza_element_repo(s->repo,m);
    }
    distrugeMedicament(m);
    return erori;
}

int sterge_service(ServiceFarmacie* s,int cod)
{
    return sterge_repo(s->repo,cod);
}
