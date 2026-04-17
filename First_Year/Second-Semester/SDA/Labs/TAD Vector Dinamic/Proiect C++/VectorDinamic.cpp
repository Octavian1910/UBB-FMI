#include "VectorDinamic.h"
#include "IteratorVectorDinamic.h"
#include <exception>

using namespace std;

void VectorDinamic::redim() {
    cp = 2 * cp;
    TElem *eNou = new int[cp];

    for (int i = 0 ; i < n ; ++i)
        eNou[i] = e[i];

    delete[] e;

    e = eNou;
}

VectorDinamic::VectorDinamic(int cp) {
    this->cp = cp;
    e = new TElem[cp];
    this->n = 0;
}



VectorDinamic::~VectorDinamic() {
    delete[] e;
}



int VectorDinamic::dim() const{
	return n;
}



TElem VectorDinamic::element(int i) const{
	return e[i];
}



void VectorDinamic::adaugaSfarsit(TElem e) {
    if (n == cp)
        redim();

    this->e[n++] = e;
}


void VectorDinamic::adauga(int i, TElem e) {
    if (i < 0 || i > n)
        throw exception();

    if (n == cp)
        redim();

    for (int j = n; j > i ; j--)
       this->e[j] = this->e[j - 1];

    this->e[i] = e;
    n++;

}


TElem VectorDinamic::modifica(int i, TElem e) {
    if (i < 0 || i >= n)
        throw exception();

    TElem old_e = this->e[i];
    this->e[i] = e;

	return old_e;
}


TElem VectorDinamic::sterge(int i) {
	if (i < 0 || i >= n)
	    throw exception();

    TElem elem_sters = this->e[i];
    for (int j = i; j < n - 1; ++j)
        e[j] = e[j + 1];
    n = n - 1;

	return elem_sters;
}

IteratorVectorDinamic VectorDinamic::iterator() {
	return IteratorVectorDinamic(*this);
}



