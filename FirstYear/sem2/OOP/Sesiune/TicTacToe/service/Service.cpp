#include "Service.h"

using std::string;

static int prioritateStare(const string& stare)
{
    if(stare=="Neinceput")
        return 0;

    if(stare=="In derulare")
        return 1;

    return 2;
}

const vector<Joc>& Service::getAll() const
{
    return repo.getAll();
}

vector<Joc> Service::getAllSorted() const
{
    auto all=repo.getAll();

    for(int i=0;i<(int)all.size();i++)
        for(int j=0;j<(int)all.size()-1;j++)
            if(prioritateStare(all[j].getStare())>prioritateStare(all[j+1].getStare()))
                std::swap(all[j],all[j+1]);

    return all;
}

void Service::addJoc(int id,int dim,const string& tabla,char jucatorCurent,const string& stare)
{
    Joc joc{id,dim,tabla,jucatorCurent,stare};

    val.validate(joc);

    repo.add(joc);
}

void Service::updateJoc(int id,int dim,const string& tabla,char jucatorCurent,const string& stare)
{
    Joc joc{id,dim,tabla,jucatorCurent,stare};

    val.validate(joc);

    repo.update(joc);
}

Joc Service::findById(int id) const
{
    return repo.findById(id);
}