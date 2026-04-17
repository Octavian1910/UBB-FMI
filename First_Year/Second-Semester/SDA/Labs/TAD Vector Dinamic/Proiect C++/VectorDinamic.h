#pragma once
//tip de data generic (pentru moment este intreg)

typedef int TElem;

class IteratorVectorDinamic;


class VectorDinamic {

private:
	/* aici e reprezentarea */
	int cp; //capacitate
	int n; //dimensiune
	TElem *e; //elemente

    /*
    Redimensioneaza vectorul

    :pre:
    vectorul este plin (n == cp)

    :post:
    capacitatea se dubleaza (cp = 2 * cp)
    se aloca un nou vector de dimensiune cp
    elementele vechi sunt copiate in noul vector
    memoria veche este eliberata

    Complexitate: O(n)
    */
	void redim();

public:
    /*
 Creeaza un vector dinamic cu o capacitate data

 :return: obiect de tip VectorDinamic

 :pre:
 capacitate > 0

 :post:
 cp = capacitate
 n = 0
 se aloca memorie pentru elemente

 @throws exception daca capacitate <= 0

 Complexitate: O(1)
*/
    VectorDinamic (int capacitate);


    /*
     Returneaza numarul de elemente din vector

     :return: dimensiunea vectorului

     :pre:
     -

     :post:
     nu modifica vectorul

     Complexitate: O(1)
    */
    int dim() const;


    /*
     Returneaza elementul de pe pozitia i

     :return: elementul de pe pozitia i

     :pre:
     0 <= i < n

     :post:
     nu modifica vectorul

     @throws exception daca i nu este valid

     Complexitate: O(1)
    */
    TElem element(int i) const;


    /*
     Modifica elementul de pe pozitia i

     :return: valoarea veche de pe pozitia i

     :pre:
     0 <= i < n

     :post:
     elementul de pe pozitia i este inlocuit

     @throws exception daca i nu este valid

     Complexitate: O(1)
    */
    TElem modifica(int i, TElem e);


    /*
     Adauga un element la sfarsitul vectorului

     :pre:
     -

     :post:
     n creste cu 1
     elementul este adaugat la final
     daca capacitatea este depasita, se redimensioneaza

     Complexitate:
     amortizat O(1)
     worst case O(n)
    */
    void adaugaSfarsit(TElem e);


    /*
     Adauga un element pe pozitia i

     :pre:
     0 <= i <= n

     :post:
     elementul este inserat pe pozitia i
     elementele se deplaseaza la dreapta
     n creste cu 1

     @throws exception daca i nu este valid

     Complexitate: O(n)
    */
    void adauga(int i, TElem e);


    /*
     Sterge elementul de pe pozitia i

     :return: elementul sters

     :pre:
     0 <= i < n

     :post:
     elementele se deplaseaza la stanga
     n scade cu 1

     @throws exception daca i nu este valid

     Complexitate: O(n)
    */
    TElem sterge(int i);


    /*
     Creeaza un iterator pentru vector

     :return: iterator asociat vectorului

     :pre:
     -

     :post:
     iteratorul este initializat pe prima pozitie

     Complexitate: O(1)
    */
    IteratorVectorDinamic iterator();


    /*
     Distruge vectorul si elibereaza memoria

     :pre:
     -

     :post:
     memoria alocata este eliberata

     Complexitate: O(1)
    */
    ~VectorDinamic();
};







