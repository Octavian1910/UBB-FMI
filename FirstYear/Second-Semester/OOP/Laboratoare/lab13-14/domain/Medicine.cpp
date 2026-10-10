//
// Created by octav on 01.05.2026.
//

#include "Medicine.h"


const string &Medicine::get_active_substance() const
{
    return active_substance;
}

string Medicine::get_ID() const
{
    return name + "|" + producer;
}

const string &Medicine::get_name() const
{
    return name;
}

int Medicine::get_price() const
{
    return price;
}

const string &Medicine::get_producer() const
{
    return producer;
}


void Medicine::set_name(const string& new_name)
{
    this->name = new_name;
}

void Medicine::set_price(int new_price)
{
    this->price = new_price;
}

void Medicine::set_producer(const string& new_producer)
{
    this->producer = new_producer;
}

void Medicine::set_active_substance(const string& new_active_substance)
{
    this->active_substance = new_active_substance;
}
