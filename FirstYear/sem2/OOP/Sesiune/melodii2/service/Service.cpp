#include "Service.h"

#include <algorithm>

using std::sort;

Service::Service(Repo& repo, Validator& val)
    : repo{ repo }, val{ val }
{
}

void Service::add(const string& titlu,
                  const string& artist,
                  const string& gen)
{
    int id = 1;

    for (const auto& m : repo.getAll())
    {
        if (m.getId() >= id)
            id = m.getId() + 1;
    }

    Melodie mel{ id, titlu, artist, gen };

    val.valideaza(mel);

    repo.add(mel);
}

void Service::remove(int id)
{
    repo.remove(id);
}

vector<Melodie>& Service::getAll()
{
    return repo.getAll();
}

vector<Melodie> Service::sortArtist()
{
    vector<Melodie> rez = repo.getAll();

    sort(rez.begin(), rez.end(),
        [](const Melodie& m1, const Melodie& m2)
        {
            return m1.getArtist() < m2.getArtist();
        });

    return rez;
}

int Service::getNrArtist(const string& artist)
{
    int cnt = 0;

    for (const auto& m : repo.getAll())
    {
        if (m.getArtist() == artist)
            cnt++;
    }

    return cnt;
}

int Service::getNrGen(const string& gen)
{
    int cnt = 0;

    for (const auto& m : repo.getAll())
    {
        if (m.getGen() == gen)
            cnt++;
    }

    return cnt;
}