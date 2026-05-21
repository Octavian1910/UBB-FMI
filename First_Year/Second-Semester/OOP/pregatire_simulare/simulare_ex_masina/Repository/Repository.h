//
// Created by octav on 21.05.2026.
//

#ifndef SIMULARE_EX_MASINA_REPOSITORY_H
#define SIMULARE_EX_MASINA_REPOSITORY_H
#include <vector>
#include "../domain/Car.h"


class Repository
{
private:
    std::vector<Car> elements;
    string file_path;
    void read_from_file();
public:
    Repository(string file_path);
    const std::vector<Car>& get_all() const;
};


#endif //SIMULARE_EX_MASINA_REPOSITORY_H