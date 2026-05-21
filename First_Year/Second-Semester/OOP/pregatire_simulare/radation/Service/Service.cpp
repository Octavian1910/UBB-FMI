//
// Created by octav on 21.05.2026.
//

#include "Service.h"

#include <algorithm>
#include <signal.h>
#include <stdexcept>

#include "../Domain/Validator/Validator.h"


const std::vector<Radiation> &Service::get_all() const
{
    return repository.get_all();
}

std::vector<Radiation> Service::filter_by_frequency(float frequency) const
{
    const auto& response = repository.get_all();
    vector<Radiation> result;
    for (const auto& elem:response)
    {
        if (elem.get_frequency() <= frequency)
            result.push_back(elem);
    }
    return result;
}

std::vector<Radiation> Service::filter_by_type_frequency(string type_frequency) const
{
    const auto& response = repository.get_all();
    vector<Radiation> result;
    for (const auto& elem:response)
    {
        if (elem.get_type_frequency().find(type_frequency) == 0)
            result.push_back(elem);
    }
    return result;
}

std::vector<Radiation> Service::filter_for_ui(float frequency, string type_frequency) const
{
    auto result1 = filter_by_frequency(frequency);
    auto result2 = filter_by_type_frequency(type_frequency);
    vector<Radiation> final_result;

    for (const auto& elem:result1)
    {
        auto it = std::find_if(result2.begin(),result2.end(),
            [&elem](const Radiation& elem2)
            {
               return elem.get_ID() == elem2.get_ID();
            });

        if (it != result2.end())
        {
            final_result.push_back(elem);
        }
    }
    return  final_result;

}

void Service::add(int id, string description, float frequency, string type_frequency)
{
    Validator validator;
    try
    {
        Radiation rad{id,description,frequency,type_frequency};
        validator.validate(rad);
        repository.add(rad);
    }
    catch (...)
    {
        throw std::runtime_error("Ceva nu a mers bine!");
    }
}
