//
// Created by octav on 21.05.2026.
//

#ifndef RADATION_VALIDATOR_H
#define RADATION_VALIDATOR_H
#include <vector>
#include <string>

#include "../Radiation.h"
#include "ValidatorException.h"

class Validator
{
public:
    void validate(const Radiation& rad)
    {
      string errors;
      if (rad.get_description() == "")
          errors += "Invalid description!\n";

      if (rad.get_frequency() < 0.0 || rad.get_frequency() > 100.0)
      {
          errors += "Invalid frequency!\n";
      }

      bool found = false;
      std::vector<std::string> frequencies = {"alpha","beta","gamma","delta","theta"};
        for (auto type:frequencies)
        {
            if (rad.get_type_frequency() == type)
            {
                found = true;
                break;
            }
        }
        if (found == false)
            errors += "Invalid type!\n";


        if (errors.size() > 0)
        {
            throw ValidatorException(errors);
        }

    };
};


#endif //RADATION_VALIDATOR_H