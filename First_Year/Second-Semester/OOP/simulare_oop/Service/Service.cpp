//
// Created by octav on 22.05.2026.
//

#include "Service.h"
#include<algorithm>
using std::sort;

const std::vector<Postare> &Service::get_all() const
{
    return repository.get_all();
}

std::vector<Postare> Service::sort_by_creator(bool ascending) const
{
    std::vector<Postare>result = repository.get_all();
    std::sort(result.begin(),result.end(),
        [&ascending](const Postare& p1,const Postare& p2)
        {
            if (ascending == true)
            {
                return p1.get_creator() < p2.get_creator();
            }
            else
            {
                return p1.get_creator() > p2.get_creator();
            }
        });
    return result;
}


std::vector<Postare> Service::sort_by_platform(bool ascending) const
{
    std::vector<Postare>result = repository.get_all();
    std::sort(result.begin(),result.end(),
        [&ascending](const Postare& p1,const Postare& p2)
        {
            if (ascending == true)
            {
                return p1.get_platforma() < p2.get_platforma();
            }
            else
            {
                return p1.get_platforma() > p2.get_platforma();
            }
        });
    return result;
}
