#include "MelodieService.h"

#include "ServiceException.h"

const Melodie &MelodieService::find(int id) const
{
    return repo.find(id);
}

void MelodieService::remove(int id)
{
    const Melodie& mel=repo.find(id);

    string artist=mel.get_artist();

    int cnt=0;

    for(const auto& m:repo.getAll())
        if(m.get_artist()==artist)
            cnt++;

    if(cnt==1)
        throw ServiceException("Este ultima melodie a artistului!");

    repo.remove(id);
}

void MelodieService::update(int id, string title, int rank)
{
    const Melodie& rez =repo.find(id);
    Melodie melodie{id,title,rez.get_artist(),rank};
    validator.validate(melodie);
    repo.update(melodie);
}


vector<Melodie> MelodieService::getAllSorted() const
{
    auto rez = repo.getAll();
    for (int i = 0 ; i < rez.size() - 1 ; ++i)
        for (int j = i + 1 ; j < rez.size()  ; ++j)
            if (rez[i].get_rank() > rez[j].get_rank())
                std::swap(rez[i],rez[j]);
    return rez;
}

int MelodieService::countRank(int rank) const
{
    int cnt=0;

    for(const auto& m:repo.getAll())
        if(m.get_rank()==rank)
            cnt++;

    return cnt;
}
