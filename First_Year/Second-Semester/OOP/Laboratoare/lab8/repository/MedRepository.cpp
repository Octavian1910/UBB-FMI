//
// Created by octav on 01.05.2026.
//

#include "MedRepository.h"

#include <algorithm>
#include <string>

#include "RepositoryException.h"

using std::string;

int MedRepository::size() const
{
    return static_cast<int>(medicines.size());
}

void MedRepository::store(const Medicine &med)
{
    auto it = std::find_if(medicines.begin(),medicines.end(),
        [&med](const Medicine& m)
        {
            return m.get_ID() == med.get_ID();
        });

    if (it != medicines.end())
        throw RepositoryException("Medicine already exis and cant be added! \n");
    medicines.push_back(med);
}

const vector<Medicine> &MedRepository::getAll() const
{
    return medicines;
}

const Medicine &MedRepository::find(const string &ID) const
{
    auto it = std::find_if(medicines.begin(),medicines.end(),
        [&ID](const Medicine& med)
        {
            return ID==med.get_ID();
        });
    if (it == medicines.end())
        throw RepositoryException("Medicine doesnt exist and cannot be returned!\n");

    return *it; // it este un pointer
}

void MedRepository::remove(const string &ID)
{
    auto it = std::find_if(medicines.begin(),medicines.end(),
        [&ID](const Medicine& med)
        {
           return med.get_ID() == ID;
        });

    if (it == medicines.end())
        throw RepositoryException("Medicine doesnt exist!\n");

    medicines.erase(it);
}

void MedRepository::update(const Medicine &med)
{
    auto it = std::find_if(medicines.begin(),medicines.end(),
        [&med](const Medicine& m)
        {
            return med.get_ID() == m.get_ID();
        });

    if (it == medicines.end())
        throw RepositoryException("Medicine doesnt exist and cant be updated!\n");

    it->set_active_substance(med.get_active_substance());
    it->set_price(med.get_price());
}
