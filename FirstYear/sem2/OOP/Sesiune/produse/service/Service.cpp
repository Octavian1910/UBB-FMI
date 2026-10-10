#include "Service.h"

#include <algorithm>
#include <cctype>

static bool cmpPret(const Produs& p1,const Produs& p2)
{
    return p1.getPret() < p2.getPret();
}

const std::vector<Produs>& Service::getAll() const
{
    return repo.getAll();
}

std::vector<Produs> Service::getAllSorted() const
{
    auto all = repo.getAll();

    std::sort(all.begin(),all.end(),cmpPret);

    return all;
}

void Service::addProdus(int id,const std::string& nume,const std::string& tip,double pret)
{
    Produs p{id,nume,tip,pret};
    Validator::validate(p);
    repo.add(p);
}

void Service::updateProdus(int id,const std::string& nume,const std::string& tip,double pret)
{
    Produs p{id,nume,tip,pret};
    Validator::validate(p);
    repo.update(p);
}

Produs Service::findById(int id) const
{
    return repo.findById(id);
}

int Service::nrVocale(const std::string& s)
{
    int cnt = 0;

    for(char c : s)
    {
        c = (char)tolower(c);

        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            cnt++;
    }

    return cnt;
}