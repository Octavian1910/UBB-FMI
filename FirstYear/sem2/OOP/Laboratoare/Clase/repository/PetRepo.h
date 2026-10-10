//
// Created by octav on 31.03.2026.
//

#ifndef LAB4_REPO_H
#define LAB4_REPO_H
#include <vector>
#include "../domain/Pet.h"

using std::vector;

class RepoException
{
    string msg;
public:
    RepoException(string m):msg{m}{}
    string getMessage()
    {
        return msg;
    }
};


class PetRepo
{
private:
    vector<Pet> pets;
public:
    PetRepo(const PetRepo & ot) = delete;
    PetRepo() = default;
    void store(const Pet& pet)
    {
        for (const Pet& p : pets)
        {
            if (p.getType() == pet.getType() && p.getSpecies() == pet.getSpecies())
            {
                throw RepoException("Pet already exist");
            }
        }
        pets.push_back(pet);
    }

    const vector<Pet>& getAll()
    {
        return pets;
    }

};
#endif //LAB4_REPO_H