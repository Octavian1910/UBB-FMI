//
// Created by octav on 17.04.2026.
//

#include "MedRepository.h"

#include "RepositoryException.h"

void MedRepository::store(const Medicine &m)
{
    for (const Medicine& current : medicines)
    {
        if (current.get_ID() == m.get_ID())
            throw RepositoryException("Medicine already exists and can't be added!\n");
    }
    medicines.add(m);
}

void MedRepository::remove(const std::string& id) {
    for (int i = 0; i < medicines.getSize(); i++) {
        if (medicines[i].get_ID() == id) {
            medicines.removeAt(i);
            return;
        }
    }
    throw RepositoryException("Medicine doesn't exist and cannot be removed!\n");
}


void MedRepository::update(const Medicine& med) {
    for (int i = 0; i < medicines.getSize(); i++) {
        if (medicines[i].get_ID() == med.get_ID())
        {
            medicines[i].set_price(med.get_price());
            medicines[i].set_active_substance(med.get_active_substance());
            return;
        }
    }
    throw RepositoryException("Medicine doesn't exist and can't be updated!\n");}



const Medicine& MedRepository::find(const std::string& id) const {
    for (int i = 0; i < medicines.getSize(); i++) {
        if (medicines[i].get_ID() == id) {
            return medicines[i];
        }
    }
    throw RepositoryException("Medicine doesn't exist and cannot be returned!\n");}

const MyVector<Medicine> &MedRepository::getAll() const
{
    return medicines;
}

int MedRepository::size() const
{
    return medicines.getSize();
}
