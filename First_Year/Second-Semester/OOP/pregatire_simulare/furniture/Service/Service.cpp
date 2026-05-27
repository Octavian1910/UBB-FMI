#include "Service.h"
#include <algorithm>

#include "../Domain/Validator/Validator.h"

Service::Service(Repository& repository) : repository(repository)
{
}

const std::vector<Furniture>& Service::get_all() const
{
    return repository.get_all();
}

void Service::add(int id, std::string type, int nr_pieces, int time)
{
    Furniture f(id, type, nr_pieces, time);
    Validator validator;
    validator.validate(f);
    repository.add(f);
}

std::vector<Furniture> Service::filter_by_types(const std::vector<bool>& checked_types) const
{
    // ordinea: nightstand, bed, table, wardrobe
    std::vector<std::string> types = {"nightstand", "bed", "table", "wardrobe"};

    bool any_checked = false;
    for (bool checked : checked_types)
    {
        if (checked)
        {
            any_checked = true;
            break;
        }
    }

    if (!any_checked)
        return repository.get_all();

    std::vector<Furniture> result;

    for (const auto& f : repository.get_all())
    {
        for (int i = 0; i < checked_types.size() && i < types.size(); i++)
        {
            if (checked_types[i] && f.get_type() == types[i])
            {
                result.push_back(f);
                break;
            }
        }
    }

    return result;
}

std::vector<Furniture> Service::sort_by_nr_pieces() const
{
    std::vector<Furniture> result = repository.get_all();

    std::sort(result.begin(), result.end(), [](const Furniture& f1, const Furniture& f2)
    {
        return f1.get_nr_pieces() < f2.get_nr_pieces();
    });

    return result;
}

std::vector<Furniture> Service::sort_by_time() const
{
    std::vector<Furniture> result = repository.get_all();

    std::sort(result.begin(), result.end(), [](const Furniture& f1, const Furniture& f2)
    {
        return f1.get_time() < f2.get_time();
    });

    return result;
}