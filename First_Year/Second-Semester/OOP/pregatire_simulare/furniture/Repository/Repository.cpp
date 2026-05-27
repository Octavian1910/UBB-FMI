//
// Created by octav on 22.05.2026.
//

#include "Repository.h"

#include <fstream>
#include <sstream>

#include "../Domain/Validator/Validator.h"


const std::vector<Furniture> &Repository::get_all() const
{
    return elements;
}

Repository::Repository(string file_path)
{
    this->file_path = file_path;
    load_from_file();
}

void Repository::load_from_file()
{
    std::ifstream file(file_path);
    if (!file.is_open())
        throw std::runtime_error("Fisierul nu s a putut deschide");

    string line;
    while (std::getline(file,line))
    {
        if (line == "")
            continue;

        std::stringstream ss(line);
        string id,type,nr_pieces,time;
        std::getline(ss,id,',');
        std::getline(ss,type,',');
        std::getline(ss,nr_pieces,',');
        std::getline(ss,time,',');

        try
        {
            int int_id = std::stoi(id);
            int int_nr_pieces = std::stoi(nr_pieces);
            int int_time = std::stoi(time);
            Furniture f(int_id,type,int_nr_pieces,int_time);
            Validator validator;
            validator.validate(f);
            elements.push_back(f);
        }
        catch (...)
        {
            continue;
        }
    }
    file.close();
}

void Repository::store_to_file()
{
    std::ofstream file(file_path);
    for (auto elem:elements)
    {
        string text = std::to_string(elem.get_id())+","+
                        elem.get_type()+","+
                            std::to_string(elem.get_nr_pieces())+","+
                            std::to_string(elem.get_time())+'\n';
        file << text;
    }
    file.close();
}

void Repository::add(Furniture f)
{
    for (auto elem:elements)
    {
        if (elem.get_id() == f.get_id())
            throw std::runtime_error("Deja in repo!");
    }
    elements.push_back(f);
    store_to_file();

}
