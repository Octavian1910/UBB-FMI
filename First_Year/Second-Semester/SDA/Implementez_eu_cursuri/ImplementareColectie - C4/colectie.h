#pragma once; //ca sa nu dea include de mai multe ori

typedef int TElem;

class Iterator;
class Colectie;

class Nod;

typedef Nod *PNod;


class Nod
{
public:

    friend Constructor; //ca constructor sa aiba acces direct la membrii lui nod

    Nod(TElem e,PNod urm); //constructor

    TElem element();
    PNod urmator();

private:
    TElem e;
    PNod urm;

}

class Colectie
{
public:
    friend class Iterator;

    Colectie();


    void adauga(TElem elem);

    Iterator iterator() const;

    ~Colectie();
};

class Iterator
{
private:
    Iterator(const Colectie& col);

    const Colectie& colectie;

    PNod curent;

public:
    friend class Colectie;
    void prim();
    void urmatgor();
    bool valid() const;
    TElem element() const;
};
