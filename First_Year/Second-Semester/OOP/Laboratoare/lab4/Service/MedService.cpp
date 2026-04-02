#include "MedService.h"


void MedService::store(const string &name, int price, const string &producer, const string &substance) const
{
    Medicine med{name,price,producer,substance};
    validator.validate(med);
    repo.store(med);
}

const Medicine &MedService::find(const string &id) const
{
    return repo.find(id);
}

const vector<Medicine> &MedService::getAll() const
{
    return repo.getAll();
}

void MedService::update(const string &name, int price, const string &producer, const string &substance) const
{
    Medicine med{name,price,producer,substance};
    validator.validate(med);
    repo.update(med);
}

void MedService::remove(const string &id) const
{
    repo.remove(id);
}

int MedService::size() const
{
    return repo.size();
}


vector<Medicine> MedService::filter(function<bool(const Medicine &)> f) const
{
    vector<Medicine> result;

    for (const auto& med: repo.getAll())
    {
        if (f(med))
        {
            result.push_back(med);
        }
    }
    return result;}

vector<Medicine> MedService::filterByPrice(int price) const
{
    return filter([price](const Medicine& m)
    {
        return m.get_price() <= price;
    });
}

vector<Medicine> MedService::filterBySubstance(const string &substance) const
{
    return filter([substance](const Medicine& m)
    {
       return m.get_active_substance() == substance;
    });
}

vector<Medicine> MedService::sort(function<bool(const Medicine &, const Medicine &)> cmp) const
{
    vector<Medicine> v = repo.getAll();
    std::sort(v.begin(),v.end(),cmp);
    return v;}

vector<Medicine> MedService::sortByName(bool ascending) const
{
    if (ascending == true)
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
        if (m1.get_name() == m2.get_name())
        {
            return m1.get_price() < m2.get_price();
        }
        else return m1.get_name() < m2.get_name();
    });
    }
    else
    {
        return sort([](const Medicine& m1, const Medicine& m2)
        {
            if (m1.get_name() == m2.get_name())
            {
                return m1.get_price() > m2.get_price();
            }
            else return m1.get_name() > m2.get_name();
        });
    }
}

vector<Medicine> MedService::sortByProducer(bool ascending) const
{
    if (ascending == true)
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
        if (m1.get_producer() == m2.get_producer())
        {
        return m1.get_price() < m2.get_price();
        }
        else return m1.get_producer() < m2.get_producer();
        });
    }
    else
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
       if (m1.get_producer() == m2.get_producer())
       {
       return m1.get_price() > m2.get_price();
       }
       else return m1.get_producer() > m2.get_producer();
       });
    }

}


vector<Medicine> MedService::sortByActiveSubstance(bool ascending) const
{
    if (ascending == true)
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
        if (m1.get_active_substance() == m2.get_active_substance())
        {
            return m1.get_price() < m2.get_price();
        }
        else return m1.get_active_substance() < m2.get_active_substance();
    });
    }
    else
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
        if (m1.get_active_substance() == m2.get_active_substance())
        {
            return m1.get_price() > m2.get_price();
        }
        else return m1.get_active_substance() > m2.get_active_substance();
    });
    }

}




