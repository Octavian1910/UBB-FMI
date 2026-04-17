

typedef struct 
{
    int cp; // capacitatea
    int n;  //nr de elemente
    TElem* e; //vectorul efectiv
}VectorDinamic;





/*Alocam memorie pt structura
  Setam capcaitatea
  Alocam vectorul intern
  setam n = 0
*/ 
VectorDinamic* creeaza(int cp);



/*Verificam daca e plin
 Daca da redimensionam
 adaugam element
 crestem n
*/
void adaugaSf(VectorDinamic* v,TElem e)


void redim(VectorDinamic* v);

/*Acces element
 
*/ 
TElem element(VectorDinamic* v,int i);

//ITERATOR

typedef struct
{
    VectorDinamic* v;
    int curent;
}Iterator;


/*Creeaza iterator
*/ 
Iterator* creeazaIterator(VectorDinamic* v);

/*Setam iteratorul la primul element*/
void prim(Iterator* i);