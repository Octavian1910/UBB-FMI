#ifndef SERIVCE_H_
#define  SERIVCE_H_
#include "../repository/repository.h"
#include "../domain/validators/validator.h"

typedef struct
{
    RepoFarmacie* repo;
    ValidatorMedicament* validator;

}ServiceFarmacie;

ServiceFarmacie* creeaza_service_farmacie(RepoFarmacie *Repo,ValidatorMedicament* Validator);

void distruge_service_farmacie(ServiceFarmacie *s);
int nr_medicamente_service(ServiceFarmacie *s);
Medicament* cauta_medicament_service(ServiceFarmacie *s,int cod);
int adaugaService(ServiceFarmacie* s,int cod,char* nume,int concentratie,int cantitate);
int actualizeazaService(ServiceFarmacie *s,int cod,char* nume,int concentratie);
int sterge_service(ServiceFarmacie* s,int cod);

#endif
