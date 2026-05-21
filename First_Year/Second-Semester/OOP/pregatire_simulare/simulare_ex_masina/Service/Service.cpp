//
// Created by octav on 21.05.2026.
//

#include "Service.h"

#include <algorithm>

const std::vector<Car> &Service::get_all() const
{
    return repo.get_all();
}

const std::vector<Car> Service::filter_by_brand(string Brand) const
{
    const std::vector<Car>& response = repo.get_all();
    std::vector<Car> result;
    for (auto& car: response)
    {
        if (car.get_brand() == Brand )
            result.push_back(car);
    }
    return result;
}


const std::vector<Car> Service::sort_by_age(bool ascending) const
{
    std::vector<Car>result = repo.get_all();
    std::sort(result.begin(),result.end(),
        [&ascending](const Car& c1,const Car& c2)
        {
            if (ascending == true) //crescator
            {
                return c1.get_age() < c2.get_age();
            }
            else
            {
                return c1.get_age() > c2.get_age();
            }
        });
    return result;
}

