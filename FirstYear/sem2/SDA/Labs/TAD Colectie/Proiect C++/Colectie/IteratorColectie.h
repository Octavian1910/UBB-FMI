#pragma once
#include "Colectie.h"

class Colectie;
typedef int TElem;

class IteratorColectie
{
    friend class Colectie;

private:
    int* stiva;
    int varf;
    int curent;
    int frecventaCurenta;

    /*
    Coboara pe ramura stanga a arborelui pornind dintr-un nod
    si pune nodurile intalnite in stiva

    :param nod:
    nodul de la care incepe coborarea

    Complexitate: O(h), unde h este inaltimea arborelui
    */
    void coboaraStanga(int nod);

    /*
    Creeaza un iterator pentru o colectie

    :param c:
    colectia care va fi parcursa

    Complexitate: O(h), unde h este inaltimea arborelui
    */
    IteratorColectie(const Colectie& c);

    const Colectie& col;

public:

    /*
    Reseteaza iteratorul la primul element al colectiei

    Complexitate:
    O(h), unde h este inaltimea arborelui
    */
    void prim();

    /*
    Muta iteratorul la urmatorul element din colectie

    :throws exception:
    daca iteratorul nu este valid

    Complexitate:
    O(h), unde h este inaltimea arborelui
    */
    void urmator();

    /*
    Verifica daca iteratorul este valid

    :return:
    true daca iteratorul indica un element,
    false altfel

    Complexitate: O(1)
    */
    bool valid() const;

    /*
    Returneaza elementul curent indicat de iterator

    :return:
    elementul curent

    :throws exception:
    daca iteratorul nu este valid

    Complexitate: O(1)
    */
    TElem element() const;

    /*
    Distruge iteratorul si elibereaza memoria folosita de stiva

    Complexitate: O(1)
    */
    ~IteratorColectie();
};