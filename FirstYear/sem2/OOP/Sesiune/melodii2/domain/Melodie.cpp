#include "Melodie.h"

Melodie::Melodie(int id,const string& titlu,const string& artist,const string& gen): id{id},titlu{titlu},artist{artist},gen{gen}{}

int Melodie::getId() const {
    return id;
}

string Melodie::getTitlu() const {
    return titlu;
}

string Melodie::getArtist() const {
    return artist;
}

string Melodie::getGen() const {
    return gen;
}