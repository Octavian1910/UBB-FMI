#include "Repo.h"

#include <fstream>

using std::ifstream;
using std::ofstream;

Repo::Repo(const string& fileName)
    : fileName{ fileName }
{
    loadFromFile();
}

void Repo::loadFromFile()
{
    ifstream fin(fileName);

    melodii.clear();

    int id;
    string titlu;
    string artist;
    string gen;

    while (fin >> id)
    {
        fin.ignore();

        getline(fin, titlu, ';');
        getline(fin, artist, ';');
        getline(fin, gen);

        Melodie m{ id, titlu, artist, gen };
        melodii.push_back(m);
    }

    fin.close();
}

void Repo::saveToFile()
{
    ofstream fout(fileName);

    for (const auto& m : melodii)
    {
        fout << m.getId() << ";"
             << m.getTitlu() << ";"
             << m.getArtist() << ";"
             << m.getGen() << "\n";
    }

    fout.close();
}

void Repo::add(const Melodie& m)
{
    for (const auto& mel : melodii)
    {
        if (mel.getId() == m.getId())
            throw RepoException("Exista deja o melodie cu acest id!");
    }

    melodii.push_back(m);

    saveToFile();
}

void Repo::remove(int id)
{
    for (auto it = melodii.begin(); it != melodii.end(); it++)
    {
        if (it->getId() == id)
        {
            melodii.erase(it);

            saveToFile();

            return;
        }
    }

    throw RepoException("Nu exista melodia!");
}

vector<Melodie>& Repo::getAll()
{
    return melodii;
}