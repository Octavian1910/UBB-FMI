//
// Created by octav on 22.05.2026.
//

#ifndef SIMULARE_OOP_REPOSITORY_H
#define SIMULARE_OOP_REPOSITORY_H
#include <vector>

#include "../Domain/Postare.h"


class Repository
{
private:
    std::vector<Postare> elements;
    string file_path;

    /*Functia incarca din fisier in repo*/
    void read_from_file();
public:
    //constructor
    Repository(string file_path);
    //returns: vectorul cu postarile din repo
    const std::vector<Postare>& get_all() const;
};


#endif //SIMULARE_OOP_REPOSITORY_H