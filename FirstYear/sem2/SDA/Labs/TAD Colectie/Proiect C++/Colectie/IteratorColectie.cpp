#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>

using namespace std;

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    stiva = new int[col.capacitate];
    prim();
}

void IteratorColectie::coboaraStanga(int nod)
{
    while (nod != -1)
    {
        stiva[++varf] = nod;
        nod = col.st[nod];
    }
}

void IteratorColectie::prim() {
    varf = -1;
    curent = -1;
    frecventaCurenta = 0;

    coboaraStanga(col.radacina);

    if (varf != -1) {
        curent = stiva[varf--];
        frecventaCurenta = 1;
    }
}

void IteratorColectie::urmator() {
    if (!valid())
        throw exception();

    if (frecventaCurenta < col.info[curent].frecventa) {
        frecventaCurenta++;
        return;
    }

    coboaraStanga(col.dr[curent]);

    if (varf != -1) {
        curent = stiva[varf--];
        frecventaCurenta = 1;
    }
    else {
        curent = -1;
    }
}

bool IteratorColectie::valid() const {
    return curent != -1;
}

TElem IteratorColectie::element() const {
    if (!valid())
        throw exception();

    return col.info[curent].elem;
}

IteratorColectie::~IteratorColectie() {
    delete[] stiva;
}