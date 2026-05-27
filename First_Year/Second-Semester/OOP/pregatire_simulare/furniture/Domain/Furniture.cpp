//
// Created by octav on 22.05.2026.
//

#include "Furniture.h"

int Furniture::get_id() const
{
    return id;
}

int Furniture::get_nr_pieces() const
{
    return nr_pieces;
}

int Furniture::get_time() const
{
    return time;
}

const string &Furniture::get_type() const
{
    return type;
}
