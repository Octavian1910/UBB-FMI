//
// Created by octav on 20.05.2026.
//

#ifndef PREGATIRE_EXAMEN_2_REPOSITORY_H
#define PREGATIRE_EXAMEN_2_REPOSITORY_H
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../domain/Skirt.h"

using std::string;
using std::vector;

class Repository
{
private:
    string file_path;
    vector<Skirt> elements;
    void readFromFile()
    {
        std::ifstream file(file_path);
        if (file.is_open() == false)
        {
            throw std::runtime_error("File could not be opened.");
        }
        string line;
        while (std::getline(file,line))
        {
            if (line == "")
                continue;

            std::stringstream ss(line);
            string id,description,size,price,availability;
            std::getline(ss,id,',');
            std::getline(ss,description,',');
            std::getline(ss,size,',');
            std::getline(ss,price,',');
            std::getline(ss,availability,',');

            int int_ID = std::stoi(id);
            int int_price = std::stoi(price);
            bool int_availability = std::stoi(availability);
            Skirt temp_skirt(int_ID,description,size,int_price,int_availability);
            elements.push_back(temp_skirt);
        }
        file.close();
    }
public:
    Repository(const string& file_path):file_path(file_path)
    {
        readFromFile();
    }

    const vector<Skirt>& get_all() const
    {
        return elements;
    };
    Skirt& find_by_ID(int id)
    {
        auto result = std::find_if(elements.begin(),elements.end(),
            [&](const Skirt& current)
            {
               return current.get_ID() == id;
            });
        if (result == elements.end())
        {
            throw std::runtime_error("Elements not found for id :" + std::to_string(id));
        }
        return *result;
    };
};


#endif //PREGATIRE_EXAMEN_2_REPOSITORY_H