#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <inttypes.h>
#include <iostream>

using namespace std;

//TAD Colectie implementat cu arbore binar de cautare reprezentat inlantuit pe tablou

Colectie::Colectie()
{
	capacitate = 10;
    info = new Pereche[capacitate];
    st = new int[capacitate];
    dr= new int[capacitate];

    for (int i = 0 ; i < capacitate - 1 ; ++i) //folosit pt a stii urmatorul primLiber
        st[i] = i + 1;

    st[capacitate - 1] = -1; //cand primLiber ajunge la -1 se redimensioneaza
    dr[capacitate - 1] = -1;

    primLiber = 0;
    radacina = -1;
    nrElemente = 0;
}

void Colectie::redimensionare()
{
    int veche = capacitate;
    capacitate *= 2;

    Pereche* infoNou = new Pereche[capacitate];
    int* stNou = new int[capacitate];
    int* drNou = new int[capacitate];

    for (int i = 0 ; i < veche ; ++i)
    {
        infoNou[i] = info[i];
        stNou[i] = st[i];
        drNou[i] = dr[i];
    }
    for (int i = veche; i < capacitate - 1 ; ++i)
    {
        stNou[i] = i + 1;
    }

    stNou[capacitate - 1] = -1;
    primLiber = veche;
    delete[] info;
    delete[] st;
    delete[] dr;

    info = infoNou;
    st = stNou;
    dr = drNou;
}

int Colectie::aloca()  //retunreaza pozitia urmatorului primLiberl,daca nu mai e loc se redimensioneaza
{
    if (primLiber == -1)
        redimensionare();

    int poz = primLiber;
    primLiber = st[primLiber];

    st[poz] = -1;
    dr[poz] = -1;
    return poz;
}

void Colectie::dealoca(int poz)
{
    st[poz] = primLiber; //pointeaza catre lista cu primi liberi
    primLiber = poz;   //acum noul prim liber il mutam la nodul acesta care este noul prim element din lista care pointeaza catre lista cu primi liberi
}

void Colectie::adauga(TElem elem)
{
	if (radacina == -1) //daca nu exista radacina, aceasta va fii radacina
	{
	    int poz = aloca();
	    info[poz] = {elem , 1};
	    radacina = poz;
	    nrElemente++;
	    return;
	}

    int curent = radacina;
    int parinte = -1;

    while (curent != -1)  //atlfel parcurgem arborele
    {
        parinte = curent;

        if (elem == info[curent].elem) //daca exista un nod , atunci incrementam nrElemente
        {
            info[curent].frecventa++;
            nrElemente++;
            return;
        }

        if (elem < info[curent].elem)
            curent = st[curent];
        else
            curent = dr[curent];
    }

    int poz = aloca();                   //altfel trb sa l cream
    info[poz] = {elem,1};

    if (elem < info[parinte].elem)      //il legam
        st[parinte] = poz;
    else
        dr[parinte] = poz;
    nrElemente++;
}


bool Colectie::sterge(TElem elem)
{
    int curent = radacina;
    int parinte = -1;

    // mergem in ABC
    while (curent != -1 && info[curent].elem != elem) {
        parinte = curent;

        if (elem < info[curent].elem)
            curent = st[curent];
        else
            curent = dr[curent];
    }

    //nu exista
    if (curent == -1)
        return false;

    //daca exista si are frecventa > 1 , doar scadem frecventa
    if (info[curent].frecventa > 1) {
        info[curent].frecventa--;
        nrElemente--;
        return true;
    }

    //altfel frecventa este 1 si trb sters
    // caz 1 e radacina sau frunza
    if (st[curent] == -1 && dr[curent] == -1)
    {
        if (curent == radacina) //daca e radacina arborele devine gol
            radacina = -1;

        else if (st[parinte] == curent) //daca e fiul stang al parintelui
            st[parinte] = -1;
        else                            //daca e fiul drept al parintelui
            dr[parinte] = -1;

        dealoca(curent); //primLiber ajunge in locul nodului sters
    }

    // CAZ2: nu are fiu stang dar are drept
    else if (st[curent] == -1)
    {
        int fiu = dr[curent];
        if (curent == radacina) //daca e radacina , noua radacina e tocmai fiul drept
            radacina = fiu;

        else if (st[parinte] == curent) //daca nodul sters era fiu st, atunci in locul lui vine fiul
            st[parinte] = fiu;
        else                            //daca nodul sters era fiu dr, atunci in locul lui vine fiul
            dr[parinte] = fiu;

        dealoca(curent);  //primLiber ajunge in locul nodului sters
    }

    // CAZUL 3:are fiu st,dar nu are drept
    else if (dr[curent] == -1)
    {
        int fiu = st[curent];

        if (curent == radacina) //daca stergem tocmai radacina
            radacina = fiu;

        else if (st[parinte] == curent) //daca nodul sters era fiu st, atunci in locul lui vine fiul
            st[parinte] = fiu;
        else                          //daca nodul sters era fiu dr, atunci in locul lui vine fiul
            dr[parinte] = fiu;

        dealoca(curent);   //primLiber ajunge in locul nodului sters
    }

    // CAZ4 daca are si fiu st si dr
    else
    {
        // Succesorul este cel mai mic nod din subarborele drept.
        int parinteSuccesor = curent;
        int succesor = dr[curent]; //pornim din dreapta

        while (st[succesor] != -1)  //mergem max in st
        {
            parinteSuccesor = succesor;
            succesor = st[succesor];
        }

        info[curent] = info[succesor];

        if (parinteSuccesor == curent)   //daca e fix nodul din dr de la cel sters atunci pru si simplu ii dam skip la legatura
            dr[parinteSuccesor] = dr[succesor];
        else                           //altfel era in stanga de tot si atunci luam ce are el in dreapta
            st[parinteSuccesor] = dr[succesor];

        dealoca(succesor);
    }
    nrElemente--;
    return true;
}


bool Colectie::cauta(TElem elem) const {
    int curent = radacina;

    while (curent != -1) {
        if (elem == info[curent].elem)
            return true;

        if (elem < info[curent].elem)
            curent = st[curent];
        else
            curent = dr[curent];
    }

    return false;
}

int Colectie::nrAparitii(TElem elem) const
{
	int curent  = radacina;

    while (curent != -1)
    {
        if (elem == info[curent].elem)
            return  info[curent].frecventa;

        if (elem < info[curent].elem)
            curent = st[curent];
        else
            curent = dr[curent];

    }
	return 0;
}


int Colectie::dim() const {
	return nrElemente;
}


bool Colectie::vida() const {
	return nrElemente == 0;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	delete[] info;
	delete[] st;
	delete[] dr;
}


