#ifndef SERVICE_H
#define SERVICE_H

#include "../repository/repository.h"
#include "../lista/MyList.h"

typedef struct {
    RepoCheltuieli* repo;
    MyList* undoList;
} ServiceCheltuieli;

/*
 * Creeaza service-ul pentru gestionarea cheltuielilor
 * :param r: pointer la repository
 * :return: pointer la obiect ServiceCheltuieli alocat dinamic
 */
ServiceCheltuieli* creeaza_service(RepoCheltuieli* r);

/*
 * Adauga o cheltuiala noua validand datele
 * :param s: pointer la service
 * :param id: id cheltuiala
 * :param zi: zi cheltuiala
 * :param suma: suma cheltuiala
 * :param tip: tip cheltuiala
 * :return: 0 daca succes, cod eroare altfel
 */
int adauga_service(const ServiceCheltuieli* s, int id, int zi, float suma, char* tip);

/*
 * Modifica o cheltuiala existenta
 * :param s: pointer la service
 * :param id, zi, suma, tip: datele noi
 * :return: 0 la succes, cod eroare altfel
 */
int modifica_cheltuiala_service(const ServiceCheltuieli* s, int id, int zi, float suma, char* tip);

/*
 * Sterge o cheltuiala dupa ID
 * :param s: pointer la service
 * :param id: id-ul de sters
 * :return: 0 la succes, 1 daca nu exista
 */
int sterge_cheltuiala_service(const ServiceCheltuieli* s, int id);

/*
 * Realizeaza operatia de undo pentru ultima actiune
 * :param s: pointer la service
 * :return: 0 daca succes, 1 daca nu se mai poate face undo
 */
int undo(ServiceCheltuieli* s);

/*
 * Returneaza numarul total de cheltuieli
 * :param s: pointer la service
 * :return: numarul de cheltuieli (int)
 */
int get_nr_cheltuieli(const ServiceCheltuieli* s);

/*
 * Cauta o cheltuiala dupa ID prin intermediul service-ului
 * :param s: pointer la service
 * :param id: id cautat
 * :return: pointer la Cheltuiala sau NULL
 */
Cheltuiala* cauta_cheltuiala_service(const ServiceCheltuieli* s, int id);

/*
 * Returneaza lista tuturor cheltuielilor
 * :param s: pointer la service
 * :return: vector de elemente
 */
MyList* get_all_service(const ServiceCheltuieli* s);

typedef int (*FunctieComparare)(const Cheltuiala*, const Cheltuiala*);

/*
 * Sorteaza cheltuielile dupa un criteriu si o ordine
 * :param s: pointer la service
 * :param criteriu: 1-suma, 2-tip
 * :param ordine: 1-crescator, 2-descrescator
 * :return: o noua lista sortata
 */
MyList* sorteaza_service(const ServiceCheltuieli* s, int criteriu, int ordine);

/* Functii de comparare pentru sortare */
int compara_suma_crescator(const Cheltuiala* c1, const Cheltuiala* c2);
int compara_suma_descrescator(const Cheltuiala* c1, const Cheltuiala* c2);
int compara_tip_crescator(const Cheltuiala* c1, const Cheltuiala* c2);
int compara_tip_descrescator(const Cheltuiala* c1, const Cheltuiala* c2);

/* Functii de filtrare - returneaza o lista noua cu elementele filtrate */
MyList* filtrare_dupa_suma(const ServiceCheltuieli* s, float suma_limita);
MyList* filtrare_dupa_zi(const ServiceCheltuieli* s, int zi);
MyList* filtrare_dupa_tip(const ServiceCheltuieli* s, const char* tip);
MyList* filtrare_interval_zile(const ServiceCheltuieli* s, int zi_start, int zi_final);


/*Metoda sterge toate cheltuielile din repo unde ziua introdusa este egala cu ziua dorita
 * :param s: servicecheltuieli
 * :param zi: ziua care trb sa se stearga
 */
int sterge_dupa_zi(const ServiceCheltuieli* s,int zi);

/*
 * Distruge service-ul si elibereaza memoria (inclusiv undoList)
 * :param s: pointer la service
 */
void distruge_service(ServiceCheltuieli* s);



#endif