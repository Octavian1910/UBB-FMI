//
// Created by octav on 01.04.2026.
//

#ifndef LAB4_PETSERVICE_H
#define LAB4_PETSERVICE_H
#include <string>
#include "Pet.h"
#include "../repository/PetRepo.h"
using std::string;


class PetStore
{
private:
    PetRepo& rep;


public:
    PetStore(PetRepo& rep): rep{rep}{}
    PetStore(const PetStore& ot) = delete;
    PetStore() = default;

    void add(string type,string species,double price)
    {
        Pet p{type,species,price};
        rep.store(p);
    }

    const vector<Pet>& getAll()
    {
        return rep.getAll();
    }



};


#endif //LAB4_PETSERVICE_H