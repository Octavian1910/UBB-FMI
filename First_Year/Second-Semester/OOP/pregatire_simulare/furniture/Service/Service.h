#ifndef FURNITURE_SERVICE_H
#define FURNITURE_SERVICE_H

#include "../Repository/Repository.h"
#include <vector>
#include <string>

class Service
{
private:
    Repository& repository;

public:
    Service(Repository& repository);

    const std::vector<Furniture>& get_all() const;

    void add(int id, std::string type, int nr_pieces, int time);

    std::vector<Furniture> filter_by_types(const std::vector<bool>& checked_types) const;

    std::vector<Furniture> sort_by_nr_pieces() const;

    std::vector<Furniture> sort_by_time() const;
};

#endif //FURNITURE_SERVICE_H