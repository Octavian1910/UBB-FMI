#ifndef MYLIST_H
#define MYLIST_H

typedef void* ElemType;

// Tip de functie pentru distrugere element
typedef void (*DestroyFunction)(ElemType);

// Tip de functie pentru copiere element (pentru deep copy)
typedef ElemType (*CopyFunction)(ElemType);

typedef struct {
    ElemType* elems;
    int size;
    int capacity;
} MyList;

/*
 * Creeaza o lista generica vida
 * :return: pointer la obiect MyList alocat dinamic
 */
MyList* createList();

/*
 * Distruge lista si elementele sale folosind o functie specifica
 * :param l: pointer la MyList
 * :param destroyElem: pointer la functia de eliberare a memoriei pentru ElemType
 */
void destroyList(MyList* l, DestroyFunction destroyElem);

/*
 * Adauga un element in lista
 * :param l: pointer la MyList
 * :param el: elementul de adaugat (ElemType)
 */
void add(MyList* l, ElemType el);

/*
 * Returneaza elementul de pe o pozitie data
 * :param l: pointer la MyList
 * :param poz: pozitia elementului (int)
 * :return: elementul de pe pozitia respectiva
 */
ElemType get(const MyList* l, int poz);

/*
 * Modifica elementul de pe o pozitie data
 * :param l: pointer la MyList
 * :param poz: pozitia elementului (int)
 * :param el: noul element
 */
void set(const MyList* l, int poz, ElemType el);

/*
 * Returneaza numarul de elemente din lista
 * :param l: pointer la MyList
 * :return: numarul de elemente (int)
 */
int size(const MyList* l);

/*
 * Sterge elementul de pe o anumita pozitie
 * :param l: pointer la MyList
 * :param poz: pozitia de pe care se sterge
 */
void removeAt(MyList* l, int poz);

/*
 * Sterge si returneaza ultimul element din lista
 * :param l: pointer la MyList
 * :return: ultimul element din lista
 */
ElemType removeLast(MyList* l);

/*
 * Creeaza o copie superficiala a listei
 * :param l: pointer la MyList
 * :return: o noua lista care puncteaza catre aceleasi elemente
 */
MyList* copyList(MyList* l);

/*
 * Creeaza o copie profunda a listei (element cu element)
 * :param l: pointer la MyList
 * :param copyElem: functie pentru copierea unui element
 * :return: pointer la o noua lista (copie independenta)
 */
MyList* deepCopyList(const MyList* l, CopyFunction copyElem);

#endif