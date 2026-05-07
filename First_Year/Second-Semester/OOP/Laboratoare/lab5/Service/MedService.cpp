#include "MedService.h"

#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>

#include "ServiceException.h"


void MedService::store(const string &name, int price, const string &producer, const string &substance) const
{
    Medicine med{name,price,producer,substance};
    MedValidator::validate(med);
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
    MedValidator::validate(med);
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


vector<const Medicine*> MedService::filter(const function<bool(const Medicine &)>& f) const
{
    const auto& allMeds = repo.getAll();
    vector<const Medicine*> result;

    for_each(allMeds.begin(),allMeds.end(),[&](const Medicine& med)
    {
       if (f(med))
       {
           result.push_back(&med);
       }
    });
    return result;}

vector<const Medicine*> MedService::filterByPrice(int price) const
{
    return filter([price](const Medicine& m)
    {
        return m.get_price() <= price;
    });
}

vector<const Medicine*> MedService::filterBySubstance(const string &substance) const
{
    return filter([substance](const Medicine& m)
    {
        return m.get_active_substance() == substance;
    });
}

vector<const Medicine*> MedService::sort(function<bool(const Medicine&, const Medicine&)> cmp) const
{
    vector<const Medicine*> v;

    for (const auto& med : repo.getAll())
    {
        v.push_back(&med);
    }

    std::sort(v.begin(), v.end(), [&](const Medicine* m1, const Medicine* m2) {
        return cmp(*m1, *m2);
    });

    return v;}

vector<const Medicine*> MedService::sortByName(bool ascending) const
{
    if (ascending)
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
            if (m1.get_name() == m2.get_name())
                return m1.get_price() < m2.get_price();
            return m1.get_name() < m2.get_name();
        });
    }
    else
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
            if (m1.get_name() == m2.get_name())
                return m1.get_price() > m2.get_price();
            return m1.get_name() > m2.get_name();
        });
    }
}

vector<const Medicine*> MedService::sortByProducer(bool ascending) const
{
    if (ascending)
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
            if (m1.get_producer() == m2.get_producer())
                return m1.get_price() < m2.get_price();
            return m1.get_producer() < m2.get_producer();
        });
    }
    else
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
            if (m1.get_producer() == m2.get_producer())
                return m1.get_price() > m2.get_price();
            return m1.get_producer() > m2.get_producer();
        });
    }
}


vector<const Medicine*> MedService::sortByActiveSubstance(bool ascending) const
{
    if (ascending)
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
            if (m1.get_active_substance() == m2.get_active_substance())
                return m1.get_price() < m2.get_price();
            return m1.get_active_substance() < m2.get_active_substance();
        });
    }
    else
    {
        return sort([](const Medicine& m1, const Medicine& m2) {
            if (m1.get_active_substance() == m2.get_active_substance())
                return m1.get_price() > m2.get_price();
            return m1.get_active_substance() > m2.get_active_substance();
        });
    }


}

void MedService::clearRecipe()
{
      recipe.clear();
}

void MedService::addToRecipe(const string &ID)
{
    const auto& med = repo.find(ID);
    recipe.push_back(&med);
}


void MedService::generateRecipe(int n)
{
    recipe.clear();

    const auto& allMeds = repo.getAll();

    if (n > static_cast<int>(allMeds.size()))
    {
        throw ServiceException(
            "Not enough medicines!\n");
    }

    vector<const Medicine*> shuffled;

    for (const auto& med : allMeds)
    {
        shuffled.push_back(&med);
    }

    auto seed =
        std::chrono::system_clock::now()
        .time_since_epoch()
        .count();

    std::shuffle(
        shuffled.begin(),
        shuffled.end(),
        std::default_random_engine(
            static_cast<unsigned int>(seed)));

    for (int i = 0; i < n; i++)
    {
        recipe.push_back(shuffled[i]);
    }
}

int MedService::getRecipeSize() const
{
    return static_cast<int>(recipe.size());
}

void MedService::exportCSV(const string &fileName) const
{
    std::ofstream out(fileName);

    for (const auto& med : recipe)
    {
        out << med->get_ID() << ","
            << med->get_price() << ","
            << med->get_producer() << ","
            << med->get_active_substance() << "\n";
    }

    out.close();
}


void MedService::exportHTML(const string& fileName) const
{
    std::ofstream out(fileName);

    out << "<html><body>";

    for (const auto& med : recipe)
    {
        out << "<p>"
            << med->get_ID()
            << " "
            << med->get_price()
            << "</p>";
    }

    out << "</body></html>";
}




