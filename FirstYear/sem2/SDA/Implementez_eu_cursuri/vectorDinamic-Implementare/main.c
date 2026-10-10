#include "main.h"


VectorDinamic* creeaza(int cp)
{
    VectorDinamic* v= malloc(sizeof VectorDinamic));
    v->cp = 0;
    v->e = malloc(cp*sizeof(TElem));
    v->n = 0;
    
}


void adaugaSf(VectorDinamic* v,TElem e)
{
    if(v->n == v->cp)
        redim(v);

    v->e[v->n++] = e;
}

void redim(VectorDinamic* v)
{
    TElem* eNou = malloc(2* v->cp * sizeof(TElem));
    for(int i = 0 ; i < v->n ; ++i)
    {
        eNou[i] = v->e[i];
    }
    free(v->e);
    v->e = eNou; //nu inteleg aici
    v->cp *= 2;

}

TElem element(VectorDinamic* v,int i)
    return v->e[i - 1];



Iterator* creeazaIterator(VectorDinamic* v)
{
    Iterator* i = malloc(sizeof(Iterator));
    i->v = v;
    i->curent = 0;

}

void prim(Iterator* i)
{
    i->curent = 0;
}


bool valid(Iterator* i)
{
    return i->curent < dim(i->v);
}

Element* element(i)
{
    return i->v->e[i->curent];
}

