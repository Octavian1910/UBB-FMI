#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../domain/domain.h"
#include "../lista/MyList.h"

typedef struct {
    MyList* lista;
} RepoCheltuieli;

/*
 * Creeaza repository-ul pentru cheltuieli
 * :return: pointer la obiect RepoCheltuieli alocat dinamic
 */
RepoCheltuieli* creeaza_repo();

/*
 * Adauga o cheltuiala in repository
 * :param repo: pointer la RepoCheltuieli
 * :param el: cheltuiala de adaugat
 */
void adauga_repo(const RepoCheltuieli* repo, ElemType el);

/*
 * Cauta o cheltuiala dupa id
 * :param repo: pointer la RepoCheltuieli
 * :param id: id-ul cautat
 * :return: cheltuiala gasita sau NULL
 */
ElemType cauta_cheltuiala_repo(const RepoCheltuieli* repo, int id);

/*
 * Modifica o cheltuiala existenta
 * :param repo: pointer la RepoCheltuieli
 * :param el_nou: cheltuiala cu datele noi (trebuie sa aiba acelasi id)
 */
void modifica_cheltuiala_repo(const RepoCheltuieli* repo, ElemType el_nou);

/*
 * Sterge o cheltuiala din repository
 * :param repo: pointer la RepoCheltuieli
 * :param id: id-ul cheltuielii de sters
 * :return: 0 daca s-a sters cu succes, 1 altfel
 */
int sterge_cheltuiala_repo(const RepoCheltuieli* repo, int id);

/*
 * Returneaza numarul de elemente din repository
 * :param repo: pointer la RepoCheltuieli
 * :return: lungimea listei (int)
 */
int get_lungime_repo(const RepoCheltuieli* repo);

/*
 * Returneaza toate cheltuielile salvate
 * :param repo: pointer la RepoCheltuieli
 * :return: vector de elemente (ElemType*)
 */
MyList* get_all(const RepoCheltuieli* repo);

/*
 * Distruge repository-ul si elibereaza memoria
 * :param repo: pointer la RepoCheltuieli
 */
void distruge_repo(RepoCheltuieli* repo);

/*
 * Creeaza o copie a repository-ului (pentru functionalitatea de undo)
 * :param repo: pointer la RepoCheltuieli
 * :return: pointer la o copie a repository-ului
 */
RepoCheltuieli* copiaza_repo(const RepoCheltuieli* repo);

#endif