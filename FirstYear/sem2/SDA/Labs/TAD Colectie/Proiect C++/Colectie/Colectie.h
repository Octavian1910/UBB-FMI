#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

class Colectie
{
    friend class IteratorColectie;

private:
    struct Pereche {
        TElem elem;
        int frecventa;
    };

    Pereche* info;
    int* st;
    int* dr;

    int radacina;
    int primLiber;
    int capacitate;
    int nrElemente;

    /*
    Redimensioneaza tablourile interne cand nu mai exista pozitii libere

    Complexitate: O(capacitate)
    */
    void redimensionare();

    /*
    Aloca o pozitie libera din tablou

    :return:
    pozitia libera alocata

    Complexitate: O(1) amortizat
    */
    int aloca();

    /*
    Dealoca o pozitie si o introduce inapoi in lista pozitiilor libere

    :param poz:
    pozitia care trebuie eliberata

    Complexitate: O(1)
    */
    void dealoca(int poz);

public:

    /*
    Creeaza o colectie vida

    Complexitate: O(capacitate)
    */
    Colectie();

    /*
    Adauga un element in colectie

    :param e:
    elementul care trebuie adaugat

    Complexitate:
    O(h), unde h este inaltimea arborelui
    */
    void adauga(TElem e);

    /*
    Sterge o aparitie a unui element din colectie


    in locul nodului sters trebuie pus un element
    care este mai mare decat tot ce e in stanga
    si mai mic decat tot ce e in dreapta

    :param e:
    elementul care trebuie sters

    :return:
    true daca elementul a fost sters,
    false daca elementul nu exista

    Complexitate:
    O(h), unde h este inaltimea arborelui
    */
    bool sterge(TElem e);

    /*
    Verifica daca un element se afla in colectie

    :param elem:
    elementul cautat

    :return:
    true daca elementul exista,
    false altfel

    Complexitate:
    O(h), unde h este inaltimea arborelui
    */
    bool cauta(TElem elem) const;

    /*
    Returneaza numarul de aparitii ale unui element

    :param elem:
    elementul cautat

    :return:
    frecventa elementului sau 0 daca nu exista

    Complexitate:
    O(h), unde h este inaltimea arborelui
    */
    int nrAparitii(TElem elem) const;

    /*
    Returneaza numarul total de elemente din colectie,
    luand in calcul si frecventele

    :return:
    dimensiunea colectiei

    Complexitate: O(1)
    */
    int dim() const;

    /*
    Verifica daca colectia este vida

    :return:
    true daca este vida,
    false altfel

    Complexitate: O(1)
    */
    bool vida() const;

    /*
    Returneaza un iterator pe colectie

    :return:
    iterator pozitionat pe primul element

    Complexitate:
    O(h), unde h este inaltimea arborelui
    */
    IteratorColectie iterator() const;

    /*
    Distruge colectia si elibereaza memoria

    Complexitate: O(1)
    */
    ~Colectie();
};