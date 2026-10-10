#include "Matrice.h"

#include <algorithm>
#include <exception>

using namespace std;


Matrice::Matrice(int m, int n) {

    nrL = m;
    nrC = n;

    cap = new Nod;
    cap->linie = -1;
    cap->coloana = -1;

    cap->dreapta = cap;
    cap->jos = cap;

    // santinele pt coloane
    Nod* ant = cap;

    for (int j = 0; j < nrC; j++) {

        Nod* col = new Nod;

        col->linie = -1;
        col->coloana = j;

        col->dreapta = col;
        col->jos = col;

        ant->dreapta = col;
        ant = col;
    }

    ant->dreapta = cap;

    // santinele pt linii
    ant = cap;

    for (int i = 0; i < nrL; i++) {

        Nod* lin = new Nod;

        lin->linie = i;
        lin->coloana = -1;

        lin->dreapta = lin;
        lin->jos = lin;

        ant->jos = lin;
        ant = lin;
    }

    ant->jos = cap;
}



int Matrice::nrLinii() const{
	return nrL;
}


int Matrice::nrColoane() const{
	return nrC;
}


TElem Matrice::element(int i, int j) const{
	if (i < 0 || i >= nrL || j < 0 || j >= nrC)
	    throw exception();

    Nod* linie = cap->jos;

    //cautam santinela linie
    while (linie != cap && linie->linie != i)
        linie = linie->jos;

    //cautam coloana linei
    Nod *p = linie->dreapta;
    while (p != linie && p->coloana < j )
        p = p->dreapta;

    if (p != linie && p->coloana == j)
        return p->valoare;

    return NULL_TELEMENT;
}



TElem Matrice::modifica(int i, int j, TElem e)
{
    if (i < 0 || i >= nrL || j < 0 || j >=nrC)
        throw exception();

    //cautam santinela linie
    Nod* linie = cap->jos;
    while (linie != cap && linie->linie != i)
        linie = linie->jos;

    //cautam santinela coloanei
    Nod* coloana = cap->dreapta;
    while (coloana != cap && coloana->coloana != j)
        coloana = coloana->dreapta;

    //cautam pozitia pe linie
    Nod* anteriorLinie = linie;
    Nod* curentLinie = linie->dreapta;
    while (curentLinie != linie && curentLinie->coloana < j)
    {
        anteriorLinie = curentLinie;
        curentLinie = curentLinie->dreapta;
    }

    //daca exista elementul il modificam/stergem
    if (curentLinie != linie && curentLinie->coloana == j)
    {
        TElem vechi = curentLinie->valoare;

        //stergere daca trebuie
        if (e == NULL_TELEMENT)
        {
            //scoatem din linii
            anteriorLinie->dreapta = curentLinie->dreapta;

            //scatem din coloana
            Nod* anteriorColoana = coloana;
            Nod* curentColoana = coloana->jos;
            while (curentColoana != coloana && curentColoana->linie < i)
            {
                anteriorColoana = curentColoana;
                curentColoana = curentColoana->jos;
            }

            anteriorColoana->jos = curentColoana->jos;
            delete curentColoana;
        }
        else //daca nu trb sters
        {
            curentLinie->valoare = e;
        }
        return vechi;
    }
    //altfel trebuie sa inseram deoarece nu exista
    Nod* nou = new Nod;
    nou->linie = i;
    nou->coloana = j;
    nou->valoare = e;

    //inserare pe linie
    nou->dreapta = curentLinie;
    anteriorLinie->dreapta = nou;

    //inserare pe coloana
    Nod* anterioarColoana = coloana;
    Nod* curentColoana = coloana->jos;
    while (curentColoana != coloana && curentColoana->linie < i)
    {
        anterioarColoana = curentColoana;
        curentColoana = curentColoana->jos;
    }

    nou->jos = curentColoana;
    anterioarColoana->jos = nou;

    return NULL_TELEMENT;
}

Matrice::~Matrice() {


    //stergem liniile
    Nod* linie = cap->jos;

    while (linie != cap) {

        Nod* urmLinie = linie->jos;

        Nod* p = linie->dreapta;

        while (p != linie) {

            Nod* urm = p->dreapta;

            delete p;

            p = urm;
        }

        // ștergem santinela liniei
        delete linie;

        linie = urmLinie;
    }


    //stergem santinelele pt coloane
    Nod* coloana = cap->dreapta;

    while (coloana != cap) {

        Nod* urmCol = coloana->dreapta;

        delete coloana;

        coloana = urmCol;
    }

    //stergem capul santinelelor
    delete cap;
}

