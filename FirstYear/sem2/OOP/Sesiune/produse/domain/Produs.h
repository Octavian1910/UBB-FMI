#pragma once

#include <string>
using std::string;

class Produs
{
private:
    int id;
    string nume;
    string tip;
    double pret;

public:
    Produs(int id, string nume, string tip, double pret);

    int getId() const;
    const string& getNume() const;
    const string& getTip() const;
    double getPret() const;

    void setNume(const string& numeNou);
    void setTip(const string& tipNou);
    void setPret(double pretNou);
};