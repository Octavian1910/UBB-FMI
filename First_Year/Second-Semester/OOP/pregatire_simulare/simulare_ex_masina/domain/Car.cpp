//
// Created by octav on 21.05.2026.
//

#include "Car.h"


int Car::get_age() const
{
    return age;
}

const string &Car::get_brand() const
{
    return brand;
}

int Car::get_ID() const
{
    return id;
}

const string &Car::get_model() const
{
    return model;
}
