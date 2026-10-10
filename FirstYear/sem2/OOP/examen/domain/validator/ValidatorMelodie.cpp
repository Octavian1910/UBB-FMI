#include "ValidatorMelodie.h"

#include "ValidatorException.h"
#include "../domain/Melodie.h"

void ValidatorMelodie::validate(const Melodie &melodie)
{
    string errors;
    if(melodie.get_ID() <= 0)
        errors += "ID ul trb sa fie mai mare decat 0!\n";

    if (melodie.get_title().empty() == true)
        errors += "Titlul trb completat!\n";

    if (melodie.get_artist().empty() == true)
        errors += "Artistul trb completat!\n";

    if (melodie.get_rank() < 0 || melodie.get_rank() > 10)
        errors += "Rankul trb sa fie intre 0 si 10!\n";

    if (errors.empty() == false)
        throw ValidatorException(errors);
}
