#ifndef SERVICE_H_
#define SERVICE_H_

#include "../repository/repository.h"
#include "../domain/validators/validator.h"

/*
 Reprezinta service-ul aplicatiei
*/
typedef struct
{
    RepoFarmacie* repo;
    ValidatorMedicament* validator;

} ServiceFarmacie;


/*
 Creeaza service-ul farmaciei

 :param Repo: pointer la repository
 :param Validator: pointer la validator

 :return: pointer la obiect ServiceFarmacie alocat dinamic

 :pre:
 Repo != NULL

 :post:
 se aloca memorie pentru service
 service-ul contine repository-ul si validatorul
*/
ServiceFarmacie creeaza_service_farmacie(RepoFarmacie *Repo,ValidatorMedicament* Validator);



/*
 Returneaza numarul de medicamente din service

 :param s: pointer la service

 :return: numarul de medicamente

 :pre:
 s != NULL

 :post:
 se returneaza numarul de medicamente din repository
*/
int nr_medicamente_service(ServiceFarmacie *s);


/*
 Cauta un medicament dupa cod

 :param s: pointer la service
 :param cod: codul medicamentului

 :return:
 pointer la medicament daca exista
 NULL daca medicamentul nu exista

 :pre:
 s != NULL
 cod > 0

 :post:
 se returneaza medicamentul gasit sau NULL
*/
Medicament* cauta_medicament_service(ServiceFarmacie *s,int cod);


/*
 Returneaza lista tuturor medicamentelor

 :param s: pointer la service

 :return:
 vector de pointeri la medicamente

 :pre:
 s != NULL

 :post:
 se returneaza lista medicamentelor din repository
*/
Medicament** get_all_service(ServiceFarmacie *s);


/*
 Adauga sau actualizeaza un medicament

 :param s: pointer la service
 :param cod: codul medicamentului
 :param nume: numele medicamentului
 :param concentratie: concentratia medicamentului
 :param cantitate: cantitatea medicamentului

 :return:
 0 daca operatia s-a realizat cu succes
 1 daca codul nu este pozitiv
 2 daca numele este vid
 3 daca concentratia este negativa
 4 daca cantitatea este negativa

 :pre:
 s != NULL

 :post:
 daca datele sunt valide medicamentul este adaugat
 sau actualizat in repository
*/
int adaugaService(ServiceFarmacie* s,int cod,char* nume,int concentratie,int cantitate);


/*
 Actualizeaza numele si concentratia unui medicament

 :param s: pointer la service
 :param cod: codul medicamentului
 :param nume: noul nume
 :param concentratie: noua concentratie

 :return:
 0 daca actualizarea s-a realizat
 -1 daca medicamentul nu exista
 1 daca codul este invalid
 2 daca numele este invalid
 3 daca concentratia este invalida

 :pre:
 s != NULL

 :post:
 daca medicamentul exista si datele sunt valide
 numele si concentratia sunt actualizate
*/
int actualizeazaService(ServiceFarmacie *s,int cod,char* nume,int concentratie);


/*
 Sterge stocul unui medicament

 :param s: pointer la service
 :param cod: codul medicamentului

 :return:
 0 daca operatia s-a realizat
 -1 daca medicamentul nu exista

 :pre:
 s != NULL
 cod > 0

 :post:
 daca medicamentul exista cantitatea devine 0
*/
int sterge_service(ServiceFarmacie* s,int cod);


/*
 Sorteaza medicamentele dupa un criteriu

 :param s: pointer la service
 :param criteriu:
        1 - sortare dupa nume
        2 - sortare dupa cantitate
 :param ordine:
        1 - crescator
        0 - descrescator
 :param lungime: numarul de elemente returnate

 :return:
 vector de medicamente sortate

 :pre:
 s != NULL

 :post:
 se returneaza o lista sortata de medicamente
 lungime contine numarul de elemente
*/
Medicament** sortareMedicamente(ServiceFarmacie* s,int criteriu,int ordine,int *lungime);


/*
 Filtreaza medicamentele dupa un criteriu

 :param s: pointer la service
 :param criteriu:
        1 - medicamente cu cantitate mai mica decat o valoare
        2 - medicamente a caror nume incepe cu o anumita litera
 :param valoare: valoarea de filtrare
 :param nr: numarul de rezultate

 :return:
 vector de medicamente filtrate

 :pre:
 s != NULL
 valoare != NULL

 :post:
 se returneaza lista medicamentelor care respecta criteriul
 nr contine numarul de rezultate
*/
Medicament** filtrareMedicamente(ServiceFarmacie* s,int criteriu,char* valoare,int* nr);


#endif