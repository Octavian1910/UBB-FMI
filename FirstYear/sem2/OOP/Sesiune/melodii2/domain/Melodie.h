#pragma once

#include <string>

using std::string;

class Melodie {
private:
    int id;
    string titlu;
    string artist;
    string gen;

public:
    Melodie(int id, const string& titlu,const string& artist,const string& gen);

    int getId() const;

    string getTitlu() const;

    string getArtist() const;

    string getGen() const;
};