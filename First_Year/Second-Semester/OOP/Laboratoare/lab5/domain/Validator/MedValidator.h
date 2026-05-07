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
    static void validate(const Medicine& med); //static este o functie globala legata de clasa , unde poti folosi direct MedValidator:: , noi nu avem campuri interne precum v.validate
};

#endif //LAB4_VALIDATOR_H