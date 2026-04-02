#include "Medicine.h"
#include <string>
using std::string;


string Medicine::get_name() const
{
    return name;
}

int Medicine::get_price() const
{
    return price;
}

string Medicine::get_producer() const
{
    return producer;
}

string Medicine::get_active_substance() const
{
    return active_substance;
}

string Medicine::get_ID() const
{
    return name + "|" + producer;
}


//setere
void Medicine::set_name(string new_name)
{
    name = new_name;
}

void Medicine::set_price(int new_price)
{
    price = new_price;
}

void Medicine::set_producer(string new_producer)
{
    producer = new_producer;
}

void Medicine::set_active_substance(string new_active_substance)
{
    active_substance = new_active_substance;
}

