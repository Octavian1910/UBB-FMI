#pragma once

#include <vector>
#include <string>

#include "../domain/Produs.h"

using std::string;
using std::vector;

class Repository
{
private:
    vector<Produs> all;
    string fileName;

    void loadFromFile();
    void storeToFile() const;

public:
    Repository(string fileName);

    [[nodiscard]] const vector<Produs>& getAll() const;

    [[nodiscard]] Produs findById(int id) const;

    void add(const Produs& p);

    void update(const Produs& p);
};