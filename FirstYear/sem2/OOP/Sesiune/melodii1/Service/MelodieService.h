#pragma once

#include "../repository/MelodieRepository.h"
#include "../domain/validator/ValidatorMelodie.h"

class MelodieService
{
private:
    MelodieRepository& repo;
    ValidatorMelodie& validator;

public:
    MelodieService(MelodieRepository& repo,ValidatorMelodie& validator):repo(repo),validator(validator){}

    vector<Melodie> getAllSorted() const;

    const Melodie& find(int id) const;

    void update(int id,string title,int rank);

    void remove(int id);

    int countRank(int rank) const;
};