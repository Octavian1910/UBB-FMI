//
// Created by octav on 21.05.2026.
//

#include "Radiation.h"

const int Radiation::get_ID() const
{
    return ID;
}

const string &Radiation::get_description() const
{
    return description;
}

float Radiation::get_frequency() const
{
    return frequency;
}

const string &Radiation::get_type_frequency() const
{
    return type_frequency;
}
