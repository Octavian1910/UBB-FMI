//
// Created by octav on 22.05.2026.
//

#ifndef FURNITURE_REPOSITORY_H
#define FURNITURE_REPOSITORY_H
#include <vector>

#include "../Domain/Furniture.h"

class Repository
{
private:
    std::vector<Furniture> elements;
    string file_path;
    void load_from_file();
    void store_to_file();
public:
    Repository(string file_path);
    void add(Furniture f);
    const std::vector<Furniture>& get_all() const;
};


#endif //FURNITURE_REPOSITORY_H