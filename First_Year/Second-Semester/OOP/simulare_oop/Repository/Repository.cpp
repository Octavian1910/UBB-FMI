//
// Created by octav on 22.05.2026.
//

#include "Repository.h"

#include <fstream>
#include <sstream>

Repository::Repository(string file_path)
{
    this->file_path = file_path;
    read_from_file();
}

const std::vector<Postare> &Repository::get_all() const
{
    return elements;
}

void Repository::read_from_file()
{
    std::ifstream file(file_path);
    if (!file.is_open())
    {
        throw std::runtime_error("Fisierul nu s a putut deschide!");
    }

    string line;
    while (std::getline(file,line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        string cod,creator,tip,platforma;
        std::getline(ss,cod,';');
        std::getline(ss,creator,';');
        std::getline(ss,tip,';');
        std::getline(ss,platforma,';');
        int int_cod = std::stoi(cod);
        Postare p(int_cod,creator,tip,platforma);
        elements.push_back(p);
    }
    file.close();

}
