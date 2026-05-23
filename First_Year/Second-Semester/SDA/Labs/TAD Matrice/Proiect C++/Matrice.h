#pragma once

typedef int TElem;

#define NULL_TELEMENT 0

/**
* TAD Matrice - reprezentare sub forma unei matrice rare (triplete de forma <linie, coloană,
valoare> (valoare!=0)), memorate folosind o TD cu rezolvare coliziuni prin liste întrepătrunse
 *
 */
struct Triplet
{
    int linie;
    int coloana;
    TElem valoare;
};

class Matrice
{
private:
    int nr_linii;
    int nr_coloane;
    int cap; //dimensiune tabelului de dispersie
    Triplet* elemente;
    int* urm; //tabelul de dispersie
    int primLiber; //indexul primei pozitii libere

    int d(int linie,int coloana) const; //functia hash
    void redimensionare();

public:

    /*
    Creeaza o matrice rara vida sub forma unui tabel de dispersie

    :param nrLinii:
    numarul de linii

    :param nrColoane:
    numarul de coloane

    :throws exception:
    daca numarul de linii sau coloane este invalid

    Complexitate: O(cap)
    */
    Matrice(int nrLinii, int nrColoane);


    /*
    Distruge matricea si elibereaza memoria

    Complexitate: O(cap)
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

    Complexitate: O(alfa = nr_elem/capacitate) - O(1) in caz mediu, O(cap) in caz nefavorabil
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

    :param v:
    noua valoare

    :return:
    vechea valoare

    :throws exception:
    daca pozitia este invalida

    Complexitate: O(cap) - O(1) amotizat in caz mediu, O(cap) daca se face redimensionare
    */
    TElem modifica(int i, int j, TElem v);
};