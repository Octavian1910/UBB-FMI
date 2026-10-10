#include "MelodieService.h"

#include <algorithm>

#include "ServiceException.h"

vector<Melodie> MelodieService::getAllSorted() const
{
    vector<Melodie> rez=repo.getAll();

    sort(rez.begin(),rez.end(),
        [](const Melodie& m1,const Melodie& m2)
        {
            return m1.get_rank()<m2.get_rank();
        });

    return rez;
}

const Melodie& MelodieService::find(int id) const
{
    return repo.find(id);
}

void MelodieService::update(int id,string title,int rank)
{
    const Melodie& old=repo.find(id);

    Melodie m{id,title,old.get_artist(),rank};

    validator.validate(m);

    repo.update(m);
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
        throw ServiceException("This is the last song of the artist!");

    repo.remove(id);
}

int MelodieService::countRank(int rank) const
{
    int cnt=0;

    for(const auto& m:repo.getAll())
        if(m.get_rank()==rank)
            cnt++;

    return cnt;
}