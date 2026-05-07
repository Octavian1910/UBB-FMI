#pragma once
#include <vector>
#include <utility>

using namespace std;


typedef int TElem;
typedef int TPrioritate;

typedef std::pair<TElem, TPrioritate> Element;

typedef bool (*Relatie)(TPrioritate p1, TPrioritate p2);

class CP {
private:
    struct Nod
    {
        Element e;
        Nod* urm;
        Nod* prev;
    };
    Nod* prim;
    Nod* ultim;
    Relatie rel;

public:
    /*
     Constructorul implicit
     Creeaza o coada cu prioritati vida in functie de relatia r

     :pre: r este o functie de relatie valida
     :post: coada este initializata, prim si ultim sunt nullptr, rel = r

     Complexitate: \Theta(1)
    */
    CP(Relatie r);

    /*
     Adauga un element in coada, mentinand ordinea prioritatilor

     :pre: elementul e si prioritatea p sunt valide
     :post: elementul este inserat la pozitia corecta conform relatiei
            lista ramane ordonata, dimensiunea listei creste cu 1

     Complexitate:
     Caz favorabil: Theta(1) inserare la inceput
     Worst case: Theta(n) parcurgere pana la finalul listei
    */
    void adauga(TElem e, TPrioritate p);

    /*
     Acceseaza elementul cel mai prioritar

     :return: elementul cel mai prioritar
     :pre: coada nu este vida
     :post: returneaza elementul din primul nod, fara a-l sterge

     @throws exception daca coada este vida

     Complexitate: Theta(1)
    */
    Element element() const;

    /*
     Sterge elementul cel mai prioritar si il returneaza

     :return: elementul sters
     :pre: coada nu este vida
     :post: primul nod este eliminat, memoria este eliberata, dimensiunea scade cu 1

     @throws exception daca coada este vida

     Complexitate: Theta(1)
    */
    Element sterge();

    /*
     Verifica daca coada cu prioritati este vida

     :return: true daca coada nu are elemente, false altfel
     :pre: -
     :post: nu modifica starea cozii

     Complexitate: Theta(1)
    */
    bool vida() const;

    /*
     Destructorul cozii
     Elibereaza toata memoria alocata nodurilor
     Complexitate: Theta(n)
    */
    ~CP();

};