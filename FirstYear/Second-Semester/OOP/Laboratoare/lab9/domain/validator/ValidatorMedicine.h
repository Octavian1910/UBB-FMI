//
// Created by octav on 01.05.2026.
//

#pragma once

#include "../Medicine.h"

class ValidatorMedicine
{
public:
    /*
     * Validates a medicine
     * :param med: medicine to validate
     */
    static void validate(const Medicine& med);
};