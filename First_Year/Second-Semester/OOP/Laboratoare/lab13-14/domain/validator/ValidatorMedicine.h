#pragma once
#include "../Medicine.h"

class ValidatorMedicine
{
public:
    /*
     * Validates medicine
     * :param Med: medicine to validate
     */
    static void validate(const Medicine& Med);
};