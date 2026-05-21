#include "MedService.h"

void MedService::store(const string &name, int price, const string &producer, const string &active_substance) const
{
    Medicine med{name,price,producer,active_substance};
    validator.validate(med);
    repo.store(med);
}

void MedService::remove(const string &id) const
{
    repo.remove(id);
}

void MedService::update(const string &name, int price, const string &producer, const string &substance) const
{
    Medicine med{name,price,producer,substance};
    validator.validate(med);
    repo.update(med);
}

const Medicine &MedService::find(const string &id) const
{
    return repo.find(id);
}


const MyVector<Medicine> &MedService::getAll() const
{
    return repo.getAll();
}


int MedService::size() const
{
    return repo.size();
}



MyVector<const Medicine*> MedService::filterByPrice(int price) const {
    return filter([price](const Medicine& m) {
        return m.get_price() <= price;
    });
}

MyVector<const Medicine*> MedService::filterBySubstance(const std::string& substance) const {
    return filter([substance](const Medicine& m) {
        return m.get_active_substance() == substance;
    });
}


MyVector<const Medicine*> MedService::sortByName(bool ascending) const {
    return sortBy([](const Medicine& m) {
        return m.get_name();
    }, ascending);
}

MyVector<const Medicine*> MedService::sortByProducer(bool ascending) const {
    return sortBy([](const Medicine& m) {
        return m.get_producer();
    }, ascending);
}

MyVector<const Medicine*> MedService::sortByActiveSubstance(bool ascending) const {
    return sortBy([](const Medicine& m) {
        return m.get_active_substance();
    }, ascending);
}