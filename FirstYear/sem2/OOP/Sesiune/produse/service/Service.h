#pragma once

#include "../repository/Repository.h"
#include "../domain/validator/Validator.h"

class Service
{
private:
    Repository& repo;
    Validator& val;

public:
    Service(Repository& repo, Validator& val) : repo{repo}, val{val} {}

    const std::vector<Produs>& getAll() const;
    std::vector<Produs> getAllSorted() const;

    void addProdus(int id,const std::string& nume,const std::string& tip,double pret);
    void updateProdus(int id,const std::string& nume,const std::string& tip,double pret);

    Produs findById(int id) const;

    static int nrVocale(const std::string& s) ;
};