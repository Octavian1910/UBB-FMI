//
// Created by octav on 21.05.2026.
//

#ifndef SIMULARE_EX_MASINA_SERVICE_H
#define SIMULARE_EX_MASINA_SERVICE_H
#include "../Repository/Repository.h"

class Service
{
private:
    Repository& repo;
public:
    Service(Repository& repo):repo(repo){}
    const std::vector<Car>& get_all() const;
    const std::vector<Car> filter_by_brand(string Brand) const;
    const std::vector<Car> sort_by_age(bool ascending) const;
};


#endif //SIMULARE_EX_MASINA_SERVICE_H