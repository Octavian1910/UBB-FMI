#ifndef REPO_H_
#define REPO_H_

#include "../domain/medicament.h"

/*
 Reprezinta repository-ul de medicamente
*/
typedef struct
{
    Medicament** elemente;
    int lungime;
    int capacitate;
} RepoFarmacie;


/*
 Creeaza un repository gol

 :return: pointer la obiect RepoFarmacie alocat dinamic

 :pre:
 -

 :post:
 se aloca memorie pentru repository
 lungime = 0
 capacitate initiala este setata
*/
RepoFarmacie* creeazaRepo();


/*
 Distruge repository-ul si elibereaza memoria

 :param v: pointer la repository

 :pre:
 v != NULL

 :post:
 toate medicamentele sunt distruse
 memoria repository-ului este eliberata
*/
void distrugeRepo(RepoFarmacie* v);


/*
 Adauga un medicament in repository

 :param v: pointer la repository
 :param m: medicamentul de adaugat

 :pre:
 v != NULL
 m != NULL

 :post:
 daca medicamentul nu exista se adauga
 daca exista deja se actualizeaza cantitatea
*/
void adauga_repo(RepoFarmacie* v,Medicament* m);


/*
 Sterge stocul unui medicament dupa cod

 :param v: pointer la repository
 :param cod: codul medicamentului

 :return:
 0 daca operatia s-a realizat
 -1 daca medicamentul nu exista

 :pre:
 v != NULL
 cod > 0

 :post:
 cantitatea medicamentului devine 0
*/
int sterge_repo(const RepoFarmacie* v,int cod);


/*
 Cauta un medicament dupa cod

 :param v: pointer la repository
 :param cod: codul medicamentului

 :return:
 pointer la medicament daca exista
 NULL daca nu exista

 :pre:
 v != NULL
 cod > 0

 :post:
 se returneaza medicamentul gasit sau NULL
*/
Medicament* cauta_medicament_repo(const RepoFarmacie* v,int cod);


/*
 Returneaza numarul de medicamente din repository

 :param v: pointer la repository
 :return: numarul de medicamente

 :pre:
 v != NULL

 :post:
 se returneaza lungimea repository-ului
*/
int nr_medicamente_repo(const RepoFarmacie* v);


/*
 Actualizeaza un medicament din repository

 :param v: pointer la repository
 :param m: medicamentul cu datele noi

 :return:
 0 daca actualizarea s-a realizat
 -1 daca medicamentul nu exista

 :pre:
 v != NULL
 m != NULL

 :post:
 numele si concentratia medicamentului sunt actualizate
*/
int actualizeaza_element_repo(const RepoFarmacie* v,Medicament* m);


/*
 Returneaza lista tuturor medicamentelor

 :param v: pointer la repository
 :return: vector de pointeri la medicamente

 :pre:
 v != NULL

 :post:
 se aloca un vector cu toate medicamentele din repository
*/
Medicament** get_all_repo(const RepoFarmacie* v);


/*
 Returneaza lungimea repository-ului

 :param v: pointer la repository
 :return: lungimea repository-ului

 :pre:
 v != NULL

 :post:
 se returneaza numarul de medicamente
*/
int get_lungime_repo(const RepoFarmacie* v);


/*
 Returneaza capacitatea repository-ului

 :param v: pointer la repository
 :return: capacitatea repository-ului

 :pre:
 v != NULL

 :post:
 se returneaza capacitatea vectorului
*/
int get_capacitate_repo(const RepoFarmacie* v);


#endif