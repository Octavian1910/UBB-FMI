//
// Created by octav on 17.04.2026.
//

#include "Medicine.h"


const string &Medicine::get_name() const
{
    return name;
}

const string &Medicine::get_producer() const
{
    return producer;
}

int Medicine::get_price() const
{
    return price;
}

const string &Medicine::get_active_substance() const
{
    return active_substance;
}

string Medicine::get_ID() const
{
    return name + "|" + producer;
}

void Medicine::set_name(const string &new_name)
{
    name = new_name;
}

void Medicine::set_price(int new_price)
{
    price = new_price;
}

void Medicine::set_producer(const string &new_producer)
{
    producer = new_producer;
}

void Medicine::set_active_substance(const string &new_active_substance)
{
    active_substance = new_active_substance;
}
