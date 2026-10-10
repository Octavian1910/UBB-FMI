//
// Created by octav on 24.03.2026.
//

#include "colectie.h"

#include <iostream>

Nod::Nod(TElem e,PNod urm)
{
    this->e = e;
    this->urm = urm;
}

TElem Nod::element()
{
    return e;
}

PNod Nod::urmator()
{
    return urm;
}

Colectie::Colectie()
{
    prim = nullptr;
}

void Colectie::adauga(TElem e)
{
    PNod q = new Nod(e,nullptr);
    q->urm = prim;
    prim = q;
}

