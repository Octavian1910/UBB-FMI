//
// Created by octav on 22.05.2026.
//

#ifndef SIMULARE_OOP_SERVICE_H
#define SIMULARE_OOP_SERVICE_H
#include "../Repository/Repository.h"
#include <vector>
using std::vector;


class Service
{
private:
    Repository& repository;
public:
    //constructor
    Service(Repository& repository):repository(repository){}
    //returns: vector cu postarile salvate in repo
    const std::vector<Postare>& get_all() const;
    /*
     *returneaza un vector sortat dupa creator
     * param:ascending , daca e true atunci sorteaza creascator altfel descrescator
     */
    vector<Postare> sort_by_creator(bool ascending) const;

    /*
     *returneaza un vector sortat dupa platforma
     * param:ascending , daca e true atunci sorteaza creascator altfel descrescator
     */
    vector<Postare> sort_by_platform(bool ascending) const;
};


#endif //SIMULARE_OOP_SERVICE_H