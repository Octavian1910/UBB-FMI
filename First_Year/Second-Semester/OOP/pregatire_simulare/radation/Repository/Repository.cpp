//
// Created by octav on 21.05.2026.
//

#include "Repository.h"

#include <fstream>
#include <sstream>

#include "../Domain/Validator/Validator.h"


Repository::Repository(string file_path):file_path(file_path)
{
    load_from_file(file_path);
}

const vector<Radiation>& Repository::get_all() const
{
    return elements;
}

void Repository::load_from_file(string file_path)
{
    elements.clear();
   std::ifstream file(file_path);
    if (!file.is_open())
    {
        throw std::runtime_error("File couldnt be opened!");
    }

    string line;
    while (std::getline(file,line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        //6,scanare echipament,55.3,alpha
        string ID,description,frequency,type_frequency;
        std::getline(ss,ID,',');
        std::getline(ss,description,',');
        std::getline(ss,frequency,',');
        std::getline(ss,type_frequency,',');
        int int_ID = std::stoi(ID);
        float float_frequency = std::stof(frequency);
        Radiation rad{int_ID,description,float_frequency,type_frequency};
        Validator validator;
        try
        {
            validator.validate(rad);
            elements.push_back(rad);
        }
        catch (ValidatorException& e)
        {
            std::runtime_error("Teapa");
            continue;
        }
    }

}

void Repository::add(const Radiation &rad)
{
    elements.push_back(rad);
}
