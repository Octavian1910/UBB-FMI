//
// Created by octav on 01.04.2026.
//

#include "MedValidator.h"

#include "ValidatorException.h"

void MedValidator::validate(Medicine& med)
{
    string errors = "";
    if(med.get_price() < 0)
        errors += "Price is not valid!It must be greater than 0!\n";
    if (med.get_name() == "")
        errors += "Name cant be null!\n";
    if (med.get_producer() == "")
        errors += "Producer cant be null!\n";
    if (med.get_active_substance() == "")
        errors += "Active substance cant be null!\n";

    if (errors.size() > 0)
    {
        throw ValidatorException(errors);
    }
}
