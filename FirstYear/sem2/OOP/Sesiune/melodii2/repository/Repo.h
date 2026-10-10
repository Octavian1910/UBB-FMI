#pragma once

#include "../domain/Melodie.h"
#include "../repository/RepoException.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Repo {
private:
    vector<Melodie> melodii;
    string fileName;

    void loadFromFile();
    void saveToFile();

public:
    Repo(const string& fileName);

    void add(const Melodie& m);

    void remove(int id);

    vector<Melodie>& getAll();
};