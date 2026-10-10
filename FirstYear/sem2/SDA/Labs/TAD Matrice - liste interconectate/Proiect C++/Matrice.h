#pragma once

typedef int TElem;

#define NULL_TELEMENT 0

struct Nod
{
    int linie;
    int coloana;
    TElem valoare;

    Nod* dreapta;
    Nod* jos;
};

class Matrice {

private:
	int nrL;
	int nrC;

    Nod* cap;


public:

	/*
    Creeaza o matrice rara vida

    :param nrLinii:
    numarul de linii

    :param nrColoane:
    numarul de coloane

    :throws exception:
    daca numarul de linii sau coloane este invalid

    Complexitate: O(nrLinii + nrColoane)
    */
	Matrice(int nrLinii, int nrColoane);

	/*
    Distruge matricea si elibereaza memoria

    Complexitate: O(numar_noduri)
    */
	~Matrice();

	/*
    Returneaza elementul de pe pozitia (i, j)

    :param i:
    linia elementului

    :param j:
    coloana elementului

    :return:
    valoarea elementului sau NULL_TELEMENT

    :throws exception:
    daca pozitia este invalida

    O(nrL + nrC)
    */
	TElem element(int i, int j) const;

	/*
    Returneaza numarul de linii

    :return:
    numarul de linii

    Complexitate: O(1)
    */
	int nrLinii() const;

	/*
    Returneaza numarul de coloane

    :return:
    numarul de coloane

    Complexitate: O(1)
    */
	int nrColoane() const;

	/*
    Modifica elementul de pe pozitia (i, j)

    :param i:
    linia elementului

    :param j:
    coloana elementului

    :param e:
    noua valoare

    :return:
    vechea valoare

    :throws exception:
    daca pozitia este invalida

    Complexitate: O(numar_elemente_linie + numar_elemente_coloana)
    */
	TElem modifica(int i, int j, TElem);

};