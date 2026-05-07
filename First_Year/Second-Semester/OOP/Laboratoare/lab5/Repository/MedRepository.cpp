
#include "MedRepository.h"
#include "RepositoryException.h"
#include <algorithm>


void MedRepository::store(const Medicine &med)
{
    auto it = std::find_if(medicines.begin(),medicines.end(),
    [&med](const Medicine& m)
    {
        return m.get_ID() == med.get_ID();
    });

    if (it != medicines.end())
    {
        throw RepositoryException("Medicine already exis and cant be added! \n");
    }
    medicines.push_back(med);
}

void MedRepository::update(const Medicine &med)
{
    auto it = std::find_if(medicines.begin(),medicines.end(),
        [&med](const Medicine& m)
        {
            return m.get_ID() == med.get_ID();
        });
    if (it == medicines.end())
    {
        throw RepositoryException("Medicine doesnt exist and cant be updated!\n");
    }
    it->set_active_substance(med.get_active_substance());
    it->set_price(med.get_price());
}

const Medicine& MedRepository::find(const string& id) const
{
    auto it = std::find_if(medicines.begin(), medicines.end(),
        [&id](const Medicine& m)
        {
            return m.get_ID() == id;
        });

    if (it == medicines.end())
    {
        throw RepositoryException("Medicine doesnt exist and cannot be returned!\n");
    }

    return *it;
}

void MedRepository::remove(const string& id)
{
    auto it = std::find_if(medicines.begin(),medicines.end(),
        [&id](const Medicine& m)
        {
            return m.get_ID() == id;
        });

    if (it == medicines.end())
    {
        throw RepositoryException("Medicine doesnt exist!\n");
    }

    medicines.erase(it);
}


const vector<Medicine> &MedRepository::getAll() const
{
    return medicines;
}

int MedRepository::size() const
{
    return static_cast<int>(medicines.size());
}
