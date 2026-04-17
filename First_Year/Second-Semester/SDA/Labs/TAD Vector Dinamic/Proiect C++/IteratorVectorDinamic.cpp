#include "IteratorVectorDinamic.h"

#include <exception>

#include "VectorDinamic.h"


IteratorVectorDinamic::IteratorVectorDinamic(const VectorDinamic& _v) :

    v(_v)
    {
        curent = 0;
    }



void IteratorVectorDinamic::prim() {
	curent = 0;
}



bool IteratorVectorDinamic::valid() const{
	if (curent < 0 || curent >= v.dim())
	    return false;

	return true;
}



TElem IteratorVectorDinamic::element() const{
	if (!valid())
	    throw std::exception();
	return v.element(curent);
}



void IteratorVectorDinamic::urmator() {
	if (!valid())
	    throw std::exception();
    curent++;
}

