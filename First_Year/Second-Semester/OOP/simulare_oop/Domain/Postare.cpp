//
// Created by octav on 22.05.2026.
//

#include "Postare.h"

int Postare::get_cod() const
{
    return cod;
}

const string &Postare::get_creator() const
{
    return creator;
}

const string &Postare::get_platforma() const
{
    return platforma;
}

const string &Postare::get_tip() const
{
    return tip;
}
