
#include "MedRepository.h"
#include "RepositoryException.h"


void MedRepository::store(const Medicine &med)
{
    for (const Medicine& current : medicines)
    {
        if (current.get_ID() == med.get_ID())
        {
            throw RepositoryException("Medicine already exist and cant be added!\n");
        }
    }
    medicines.push_back(med);
}

void MedRepository::update(const Medicine &med)
{
    for (Medicine& current : medicines)
    {
        if (current.get_ID() == med.get_ID())
        {
            current.set_active_substance(med.get_active_substance());
            current.set_price(med.get_price());
            return;
        }
    }
    throw RepositoryException("Medicine doesnt exist and cant be updtaed!\n");
}

const Medicine& MedRepository::find(const string& id) const
{
    for (const Medicine& current : medicines)
    {
        if (current.get_ID() == id)
        {
            return current;
        }
    }
    throw RepositoryException("Medicine doesnt exist and cannot be returned!\n");
}

void MedRepository::remove(const string& id)
{
    for (auto it = medicines.begin(); it != medicines.end(); ++it)
    {
        if (it->get_ID() == id)
        {
            medicines.erase(it);
            return;
        }
    }
    throw RepositoryException("Medicine doesnt exist!\n");
}


const vector<Medicine> &MedRepository::getAll() const
{
    return medicines;
}

int MedRepository::size() const
{
    return static_cast<int>(medicines.size());
}
