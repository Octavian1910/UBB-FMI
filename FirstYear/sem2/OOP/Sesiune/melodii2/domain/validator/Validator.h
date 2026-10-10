#pragma once

#include "../domain/Melodie.h"
#include "../domain/validator/ValidatorException.h"

class Validator {
public:
    void valideaza(const Melodie& m);
};