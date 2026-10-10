#pragma once

#include "../repository/Repo.h"
#include "../domain/validator/Validator.h"

#include <vector>

using std::vector;

class Service {
private:
    Repo& repo;
    Validator& val;

public:
    Service(Repo& repo, Validator& val);

    void add(const string& titlu,
             const string& artist,
             const string& gen);

    void remove(int id);

    vector<Melodie>& getAll();

    vector<Melodie> sortArtist();

    int getNrGen(const string& gen);

    int getNrArtist(const string& artist);
};