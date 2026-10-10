#pragma once
#include <vector>
#include <string>
#include "../domain/Melodie.h"
using std::vector;
using std::string;

class MelodieRepository
{
private:
    vector<Melodie> melodii;
    string fileName;

    /*incarca din fisier in repo*/
    void loadFromFile();

    /*incarca din repo in fisier*/
    void storeToFile() const;

public:
    /*
     * Constructor pt repo
     * param fileName este numele fisieruuli unde vom salva datele
     */
    MelodieRepository(const string& fileName);

    /*
     * Metoda cauta in repo o melodie cu id ul dorit
     * pre : id este un int
     * post : daca melodia exista o returneaza
     * arunca: arunca RepositoryException daca nu se afla in repo
     */
    const Melodie& find(int id) const;

    /*
    * Metoda cauta in repo o melodie cu id ul dorit
    * pre : id este un int
    * post : daca melodia exista o updateaza
    * arunca: arunca RepositoryException daca nu se afla in repo
    */
    void update(const Melodie& melodie);

    /*
    * Metoda cauta in repo o melodie cu id ul dorit
    * pre : id este un int
    * post : daca melodia exista o sterge
    * arunca: arunca RepositoryException daca nu se afla in repo
    */
    void remove(int id);

    /*
    * Metoda returneaza repoul
    * pre :-
    * post : un vector cu Melodii
    */
    const vector<Melodie>& getAll() const;


};


