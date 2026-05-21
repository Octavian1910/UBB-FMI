#include "MedValidator.h"
#include "ValidatorException.h"

#include <string>

void MedValidator::validate(const Medicine& med) {
    std::string errors;

    if (med.get_price() <= 0)
        errors += "Price is not valid! It must be greater than 0!\n";

    if (med.get_name().empty())
        errors += "Name can't be null!\n";

    if (med.get_producer().empty())
        errors += "Producer can't be null!\n";

    if (med.get_active_substance().empty())
        errors += "Active substance can't be null!\n";

    if (!errors.empty())
        throw ValidatorException(errors);
}