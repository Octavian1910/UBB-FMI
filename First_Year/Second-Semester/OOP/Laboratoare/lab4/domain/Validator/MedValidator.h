//
// Created by octav on 01.04.2026.
//

#ifndef LAB4_VALIDATOR_H
#define LAB4_VALIDATOR_H
#include "../Medicine.h"

class MedValidator
{
private:
public:
    /*
     * Validates a medicine
     * :param med: medicine to validate
     * :throws: ValidatorException if invalid
     */
    void validate(Medicine& med);
};

#endif //LAB4_VALIDATOR_H