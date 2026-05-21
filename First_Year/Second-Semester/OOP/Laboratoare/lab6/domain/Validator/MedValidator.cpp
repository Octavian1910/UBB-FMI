#include "MedValidator.h"

#include "ValidatorException.h"

void MedValidator::validate(const Medicine& med)
{
    string errors;
    if(med.get_price() < 0)
        errors += "Price is not valid!It must be greater than 0!\n";
    if (med.get_name().empty())
        errors += "Name cant be null!\n";
    if (med.get_producer().empty())
        errors += "Producer cant be null!\n";
    if (med.get_active_substance().empty())
        errors += "Active substance cant be null!\n";

    if (!errors.empty())
    {
        throw ValidatorException(errors);
    }
}
