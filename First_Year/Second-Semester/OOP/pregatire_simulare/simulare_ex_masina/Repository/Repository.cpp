//
// Created by octav on 21.05.2026.
//

#include "Repository.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void Repository::read_from_file()
{
    std::ifstream file(file_path);
    if (file.is_open() == false)
    {
        throw std::runtime_error("File could not be opened!");
    }

    string line;
    while (std::getline(file,line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        string id,brand,model,age;
        std::getline(ss,id,',');
        std::getline(ss,brand,',');
        std::getline(ss,model,',');
        std::getline(ss,age,',');

        int int_ID = std::stoi(id);
        int int_age = std::stoi(age);
        Car car(int_ID,brand,model,int_age);
        elements.push_back(car);
    }
    file.close();
}

Repository::Repository(string file_path):file_path(file_path)
{
    read_from_file();
}


const std::vector<Car>& Repository::get_all() const
{
    return elements;
}
