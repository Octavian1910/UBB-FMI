//
// Created by octav on 22.05.2026.
//

#include "Validator.h"

#include <csignal>
#include <stdexcept>
#include <vector>

#include "../Furniture.h"


void Validator::validate(Furniture f)
{
    std::vector<string> lista = {"bed","table","wardrobe","nightstand"};
    bool ok = false;
    for (auto elem:lista)
    {
        if (f.get_type() == elem)
        {
            ok = true;
        }
    }

    if (ok == false)
        throw std::runtime_error("Type is not good!");
}
