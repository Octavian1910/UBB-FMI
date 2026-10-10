#pragma once

#include <vector>
#include <string>

#include "../repository/Repository.h"
#include "../domain/validator/Validator.h"

using std::string;
using std::vector;

class Service
{
private:
    Repository& repo;
    Validator& val;

public:
    Service(Repository& repo,Validator& val):repo{repo},val{val}{}

    const vector<Joc>& getAll() const;
    vector<Joc> getAllSorted() const;

    void addJoc(int id,int dim,const string& tabla,char jucatorCurent,const string& stare);
    void updateJoc(int id,int dim,const string& tabla,char jucatorCurent,const string& stare);

    Joc findById(int id) const;
};