//
// Created by octav on 20.05.2026.
//

#ifndef PREGATIRE_EXAMEN_2_SERVICE_H
#define PREGATIRE_EXAMEN_2_SERVICE_H
#include <map>

#include "../Repository/Repository.h"

class Service
{
private:
    Repository& repo;
public:
    Service(Repository& repo) : repo{repo}{}
    const vector<Skirt>& get_all() const { return repo.get_all(); };
    void rentSkirt(int id)
    {
      Skirt& skirt = repo.find_by_ID(id);
        if (skirt.get_availability() == false)
        {
            throw std::runtime_error("Skirt is arleady rented.");
        }
        skirt.set_availability(false);
    }

    std::vector<Skirt> sortSkirtsBySize()
    {
        vector<Skirt> copy_result = repo.get_all();
        std::map<std::string,int> sizeMap;
        sizeMap["xs"] = 0;
        sizeMap["s"] = 1;
        sizeMap["m"] = 2;
        sizeMap["l"] = 3;
        sizeMap["xl"] = 4;
        sizeMap["xxl"] = 5;
        std::sort(copy_result.begin(),copy_result.end(),
            [&sizeMap](const Skirt &skirt1,const Skirt &skirt2)
            {
               return sizeMap[skirt1.get_size()] < sizeMap[skirt2.get_size()];
            });
        return copy_result;
    }


    vector<Skirt> sortSkirtsByPrice()
    {
        vector<Skirt> copy_result = repo.get_all();
        std::sort(copy_result.begin(),copy_result.end(),
            [](const Skirt& sk1,const Skirt& sk2)
            {
               return sk1.get_price() < sk2.get_price();
            });
     return copy_result;
    }
};


#endif //PREGATIRE_EXAMEN_2_SERVICE_H