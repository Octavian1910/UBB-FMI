//
// Created by octav on 21.05.2026.
//

#ifndef RADATION_REPOSITORY_H
#define RADATION_REPOSITORY_H
#include <vector>
#include "../Domain/Radiation.h"
using std::vector;


class Repository
{
private:
    vector<Radiation> elements;
    string file_path;
    void load_from_file(string file_path);
    void save_to_file();
public:
    Repository(string file_path);
    void add(const Radiation& rad);
    const vector<Radiation>& get_all() const;

};


#endif //RADATION_REPOSITORY_H