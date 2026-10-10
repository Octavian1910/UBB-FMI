#include "Produs.h"

#include <utility>

Produs::Produs(int id, string nume, string tip, double pret) : id{id},nume{std::move(nume)},tip{std::move(tip)},pret{pret}
{
}

int Produs::getId() const
{
    return id;
}

const string& Produs::getNume() const
{
    return nume;
}

const string& Produs::getTip() const
{
    return tip;
}

double Produs::getPret() const
{
    return pret;
}

void Produs::setNume(const string& numeNou)
{
    nume = numeNou;
}

void Produs::setTip(const string& tipNou)
{
    tip = tipNou;
}

void Produs::setPret(double pretNou)
{
    pret = pretNou;
}