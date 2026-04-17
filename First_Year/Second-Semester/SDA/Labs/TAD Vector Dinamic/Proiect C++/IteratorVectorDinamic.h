#pragma once
#include "VectorDinamic.h"

class IteratorVectorDinamic {

    friend class VectorDinamic;
private:

    /*
    Creeaza un iterator pentru vector

    :return: iterator asociat vectorului dat

    :pre:
    vectorul trebuie sa existe

    :post:
    iteratorul este initializat pe prima pozitie (curent = 0)

    Complexitate: O(1)
    */
    IteratorVectorDinamic(const VectorDinamic&);

    //contine o referinta catre containerul pe care il itereaza
    const VectorDinamic& v;

    int curent;

    /* aici e reprezentarea specifica a iteratorului */

public:
    /*
     Pozitioneaza iteratorul pe prima pozitie din vector

     :pre:
     -

     :post:
     curent = 0

     Complexitate: O(1)
    */
    void prim();


    /*
     Muta iteratorul pe urmatoarea pozitie

     :pre:
     iteratorul trebuie sa fie valid

     :post:
     curent este incrementat cu 1

     @throws exception daca iteratorul nu este valid

     Complexitate: O(1)
    */
    void urmator();


    /*
     Verifica daca iteratorul este valid

     :pre:
     -

     :post:
     returneaza true daca 0 <= curent < v.dim()
     returneaza false in caz contrar

     Complexitate: O(1)
    */
    bool valid() const;


    /*
     Returneaza elementul de pe pozitia curenta

     :return: elementul de pe pozitia curenta

     :pre:
     iteratorul trebuie sa fie valid

     :post:
     nu modifica iteratorul

     @throws exception daca iteratorul nu este valid

     Complexitate: O(1)
    */
    TElem element() const;

};