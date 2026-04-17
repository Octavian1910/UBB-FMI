
#include "CP.h"
#include <exception>
#include <stdio.h>

using namespace std;

using std::exception;

CP::CP(Relatie r) {
	prim = nullptr;
    ultim = nullptr;
    rel = r;
}


void CP::adauga(TElem e, TPrioritate p) {
	Nod* nou = new Nod;
    nou->e={e,p};
    nou->urm=nullptr;
    nou->prev=nullptr;

    if (vida())
    {
        prim=ultim=nou;
        return;
    }

    Nod* curent = prim;
    while (curent != nullptr && rel(curent->e.second,p))
    {
        curent = curent->urm;
    }

    if (curent == prim) //inseram la inceput
    {
        nou->urm=prim;
        prim->prev = nou;
        prim = nou;
    }
    else if (curent == nullptr) //inserare la final
    {
        ultim->urm = nou;
        nou->prev = ultim;
        ultim = nou;
    }
    else //la mijloc
    {
        Nod* prev = curent->prev;
        nou->urm = curent;
        nou->prev = prev;

        prev->urm = nou;
        curent->prev = nou;
    }
}

//arunca exceptie daca coada e vida
Element CP::element() const {
	if (vida())
	{
	    throw exception();
	}
	return prim->e;       // copy constructor;
}

Element CP::sterge() {
	if (vida())
	{
	    throw exception();
	}

    Nod* deSters = prim;
    Element rez = deSters->e;

    prim = prim->urm;
    if (prim != nullptr) //daca au mai ramas elem in coada atunci doar la primul punem prev null
    {
        prim->prev = nullptr;
    }
    else //daca exista doar un elem in coada atunci prim = ultim = nullptr
    {
        ultim = nullptr;
    }

    delete deSters;
    return rez;

}

bool CP::vida() const {
	return prim == nullptr;
}


CP::~CP() {
	while (!vida())
	{
	    sterge();
	}
};

