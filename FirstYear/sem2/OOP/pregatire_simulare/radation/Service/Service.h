//
// Created by octav on 21.05.2026.
//

#ifndef RADATION_SERVICE_H
#define RADATION_SERVICE_H
#include <vector>
#include "../Domain/Radiation.h"
#include "../Repository/Repository.h"

class Service
{
private:
    Repository& repository;
public:
    Service(Repository& repository):repository(repository){}
    const std::vector<Radiation>& get_all() const;
    //radation(int id,string description,float frequency,string type_frequency)
    void add(int id,string description,float frequency,string type_frequency);
    std::vector<Radiation> filter_by_type_frequency(string type_frequency) const;
    std::vector<Radiation> filter_by_frequency(float frequency) const;
    std::vector<Radiation> filter_for_ui(float frequency,string type_frequency) const;


};


#endif //RADATION_SERVICE_H