#include "Repository.h"

#include <fstream>
#include <sstream>

#include "RepositoryException.h"

using std::string;

Repository::Repository(string fileName)
    : fileName{std::move(fileName)}
{
    loadFromFile();
}

void Repository::loadFromFile()
{
    all.clear();

    std::ifstream fin(fileName);

    if (!fin.is_open())
        return;

    int id;
    string nume;
    string tip;
    double pret;

    while (fin >> id >> nume >> tip >> pret)
    {
        all.emplace_back(id, nume, tip, pret);
    }

    fin.close();
}

void Repository::storeToFile() const
{
    std::ofstream fout(fileName);

    for (const auto& p : all)
    {
        fout << p.getId() << " "
             << p.getNume() << " "
             << p.getTip() << " "
             << p.getPret() << "\n";
    }

    fout.close();
}

const vector<Produs>& Repository::getAll() const
{
    return all;
}

Produs Repository::findById(int id) const
{
    for (const auto& p : all)
        if (p.getId() == id)
            return p;

    throw RepositoryException("Nu exista produs cu acest id!");
}

void Repository::add(const Produs& p)
{
    for (const auto& el : all)
        if (el.getId() == p.getId())
            throw RepositoryException("Exista deja produs cu acest id!");

    all.push_back(p);
    storeToFile();
}

void Repository::update(const Produs& p)
{
    for (auto& el : all)
    {
        if (el.getId() == p.getId())
        {
            el.setNume(p.getNume());
            el.setTip(p.getTip());
            el.setPret(p.getPret());

            storeToFile();
            return;
        }
    }

    throw RepositoryException("Nu exista produs cu acest id!");
}