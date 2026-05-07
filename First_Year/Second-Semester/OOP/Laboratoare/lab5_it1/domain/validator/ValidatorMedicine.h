//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_VALIDATORMEDICINE_H
#define LAB5_IT1_VALIDATORMEDICINE_H
#include "../Medicine.h"

class ValidatorMedicine
{
public:
    /*
     * Validates a medicine
     * :param Med: medicine to validate
     */
    static void validate(const Medicine& Med);
};

#endif //LAB5_IT1_VALIDATORMEDICINE_H