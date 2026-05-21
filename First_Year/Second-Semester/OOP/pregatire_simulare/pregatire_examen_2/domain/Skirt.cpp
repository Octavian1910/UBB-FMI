//
// Created by octav on 20.05.2026.
//

#include "Skirt.h"

bool Skirt::get_availability() const
{
    return availability;
}

int Skirt::get_ID() const
{
    return ID;
}

const string &Skirt::get_name() const
{
    return name;
}

int Skirt::get_price() const
{
    return price;
}

const string &Skirt::get_size() const
{
    return size;
}

void Skirt::set_availability(bool status)
{
    availability = status;
}
