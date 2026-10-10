#include "Matrice.h"

#include <exception>
#include <bits/error_constants.h>

using namespace std;

int Matrice::d(int linie, int coloana) const
{
    return (linie*nr_coloane + coloana) % cap;
}

Matrice::Matrice(int m, int n)
{
    if (m <= 0 || n <= 0)
        throw exception();

    nr_linii = m;
    nr_coloane = n;

    cap = 10;

    elemente = new Triplet[cap];
    urm = new int[cap];

    for (int i = 0 ; i < cap ; ++i)
    {
        elemente[i].linie = -1;
        elemente[i].coloana = -1;
        elemente[i].valoare = NULL_TELEMENT;
        urm[i] = -1;
    }
    primLiber = 0;
}

Matrice::~Matrice()
{
    delete[] elemente;
    delete[] urm;
}


int Matrice::nrLinii() const{
	return nr_linii;
}


int Matrice::nrColoane() const{
	return nr_coloane;
}


TElem Matrice::element(int i, int j) const{
	if (i < 0 || i >= nr_linii || j < 0 || j >= nr_coloane)
	    throw exception();

    int poz = d(i,j);
    while (poz != -1)
    {
        if (elemente[poz].linie == i && elemente[poz].coloana == j) //daca am ajuns la elementul bun il returnam
            return elemente[poz].valoare;

        poz = urm[poz]; //altfel mergem mai departe in lant
    }

	return NULL_TELEMENT; //daca nu s a gasit
}

void Matrice::redimensionare()
{
    int vechiCap = cap;

    cap = cap * 2;
    Triplet* vechi_elemente = elemente;
    int* vechiUrm = urm;

    elemente = new Triplet[cap];
    urm = new int[cap];

    for (int i = 0 ; i < cap ; ++i)
    {
        elemente[i].linie = -1;
        elemente[i].coloana = -1;
        elemente[i].valoare = NULL_TELEMENT;
        urm[i] = -1;
    }

    primLiber = 0;
    //trb rehash pt ca se schimba cap , functia hash depinde de cap
    for (int i = 0 ; i < vechiCap ; ++i)
    {
        if (vechi_elemente[i].linie != -1)
            modifica(vechi_elemente[i].linie,vechi_elemente[i].coloana,vechi_elemente[i].valoare);
    }
    delete[] vechi_elemente;
    delete[] vechiUrm;
}


TElem Matrice::modifica(int i, int j, TElem elem)
{
    if (i < 0 || i >= nr_linii || j < 0 || j >= nr_coloane)
        throw exception();

    int poz = d(i,j); //inceputul lantului unde se poate afla elementul dorit

    int precedent = -1;
    int curent = poz;
    while (curent != -1 && !(elemente[curent].linie == i && elemente[curent].coloana == j)) //cautam folosind vectorul de dispersie elementul dorit si precedentul acestuia
    {
        precedent = curent;
        curent = urm[curent];
    }

    if (curent != -1) //elem exista deja
    {
        TElem vechi = elemente[curent].valoare;

        if (elem != NULL_TELEMENT) //daca vrem update
        {
            elemente[curent].valoare = elem;
            return  vechi;
        }
        //altfel vrem stergere
        bool gata = false;
        while (!gata)
        {
            int p = urm[curent];
            int pp = curent;

            while (p != -1 && d(elemente[p].linie,elemente[p].coloana) != curent) // cautam un elem care poate fi mutat , adica un elem cu acelasi hash
            {
                pp = p;
                p = urm[p];
            }

            if (p == -1) // nu mai exista elemente
            {
                gata = true;
            }
            else
            {
                elemente[curent] = elemente[p]; //il punem in locul potrivit daca exisat si acum gaura se muta in locul lui p
                precedent = pp;
                curent = p;
            }
        }

        if (precedent != -1) // daca exista precedent
        {
            urm[precedent] = urm[curent];
        }

        elemente[curent].linie = -1;
        elemente[curent].coloana = -1;
        elemente[curent].valoare = NULL_TELEMENT;
        urm[curent] = -1;

        if (primLiber > curent)
            primLiber = curent;

        return vechi;
    }
    //altfel elem nu exista si dorim sa l inseram
    if (elem == NULL_TELEMENT) // nu facem nimic
        return NULL_TELEMENT;

    //cautam prima poz libera , s ar putea sa nu fie primLiber deja bine din cauza redimensionarii
    while (primLiber < cap && elemente[primLiber].linie != -1)
    {
        primLiber++;
    }

    if (primLiber == cap)
    {
        redimensionare();
    }

    poz = d(i,j); //recalculam hash
    if (elemente[poz].linie == -1) //daca il putem pune direct la hash o facem direct
    {
        elemente[poz].linie = i;
        elemente[poz].coloana = j;
        elemente[poz].valoare = elem;
    }
    else //mergem prin lant pana ajungem intr o pozitie libera
    {
        int p = poz;
        while (urm[p] != -1)
        {
            p = urm[p];
        }
        elemente[primLiber].linie = i;
        elemente[primLiber].coloana = j;
        elemente[primLiber].valoare = elem;

        urm[p] = primLiber; //conectam lantul la primLiber
    }

    while (primLiber < cap && elemente[primLiber].linie != -1)  //mergem la urm primLiber
    {
        primLiber++;
    }
    return NULL_TELEMENT;


}
