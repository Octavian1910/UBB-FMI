#include "Validator.h"

void Validator::valideaza(const Melodie& m)
{
    string erori;

    if (m.getGen() != "pop" && m.getGen() != "rock" && m.getGen() != "folk" && m.getGen() != "disco")
    {
        erori += "Gen invalid!\n";
    }

    if (!erori.empty())
        throw ValidatorException(erori);
}