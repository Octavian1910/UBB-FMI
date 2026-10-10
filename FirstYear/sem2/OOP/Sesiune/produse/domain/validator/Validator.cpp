#include "Validator.h"
#include "ValidatorException.h"

using std::string;

void Validator::validate(const Produs& p)
{
    string errors;

    if (p.getNume().empty())
        errors += "Numele nu poate fi gol!\n";

    if (p.getTip().empty())
        errors += "Tipul nu poate fi gol!\n";

    if (p.getPret() < 0)
        errors += "Pretul trebuie sa fie pozitiv!\n";

    if (!errors.empty())
        throw ValidatorException(errors);
}