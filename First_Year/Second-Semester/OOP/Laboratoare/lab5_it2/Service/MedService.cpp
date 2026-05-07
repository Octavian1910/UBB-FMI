//
// Created by octav on 01.05.2026.
//

#include "MedService.h"

#include <algorithm>
#include <vector>
#include <chrono>
#include <fstream>
#include <random>

#include "ServiceException.h"


using std::vector;
using std::sort;

const Medicine &MedService::find(const string &ID) const
{
    return repo.find(ID);
}

int MedService::size() const
{
    return repo.size();
}

void MedService::store(const string &name, int price, const string &producer, const string &active_substance)
{
    Medicine med{name,price,producer,active_substance};
    ValidatorMedicine::validate(med);
    repo.store(med);
    undoActions.push_back(new UndoAdd(repo,med));
}

const vector<Medicine> &MedService::getAll() const
{
    return repo.getAll();
}

void MedService::update(const string &name, int price, const string &producer, const string &active_substance)
{
    Medicine med{name,price,producer,active_substance};
    ValidatorMedicine::validate(med);
    Medicine old_med = repo.find(med.get_ID());
    repo.update(med);
    undoActions.push_back(new UndoModify(repo,old_med));
}

void MedService::remove(const string &ID)
{
    Medicine med = repo.find(ID);
    repo.remove(ID);
    undoActions.push_back(new UndoDelete(repo,med));

}


vector<const Medicine*> MedService::filter(const function<bool(const Medicine &)> &f) const
{
    const auto& allMeds = repo.getAll();

    vector<const Medicine*> result;

    std::for_each(allMeds.begin(),allMeds.end(),
        [&](const Medicine& med)
        {
            if (f(med))
            {
                result.push_back(&med);
            }
        });
    return result;}

vector<const Medicine *> MedService::filterByPrice(int price) const
{
    return filter([price](const Medicine& med)
    {
        return med.get_price() <= price;
    });
}

vector<const Medicine *> MedService::filterBySubstance(const string &active_substance) const
{
    return filter([&active_substance](const Medicine &med)
    {
        return med.get_active_substance() == active_substance;
    });
}

vector<const Medicine*> MedService::sort(const function<bool(const Medicine&, const Medicine&)>& cmp) const
{
    vector<const Medicine*> v;
    for (const auto& med: repo.getAll())
    {
        v.push_back(&med);
    }

    std::sort(v.begin(),v.end(),[&](const Medicine* m1,const Medicine* m2)
    {
        return cmp(*m1,*m2);
    });
    return v;}

vector<const Medicine*> MedService::sortByName(bool ascending) const
{
    return sort([ascending](const Medicine& m1, const Medicine& m2)
    {
        if (m1.get_name() != m2.get_name())
        {
            if (ascending)
                return m1.get_name() < m2.get_name();

            return m1.get_name() > m2.get_name();
        }

        if (ascending)
            return m1.get_price() < m2.get_price();

        return m1.get_price() > m2.get_price();
    });
}

vector<const Medicine*> MedService::sortByProducer(bool ascending) const
{return sort([ascending](const Medicine& m1, const Medicine& m2)
    {
        if (m1.get_producer() != m2.get_producer())
        {
            if (ascending)
                return m1.get_producer() < m2.get_producer();

            return m1.get_producer() > m2.get_producer();
        }

        if (ascending)
            return m1.get_price() < m2.get_price();

        return m1.get_price() > m2.get_price();
    });
}

vector<const Medicine*> MedService::sortByActiveSubstance(bool ascending) const
{return sort([ascending](const Medicine& m1, const Medicine& m2)
    {
        if (m1.get_active_substance() != m2.get_active_substance())
        {
            if (ascending)
                return m1.get_active_substance() < m2.get_active_substance();

            return m1.get_active_substance() > m2.get_active_substance();
        }

        if (ascending)
            return m1.get_price() < m2.get_price();

        return m1.get_price() > m2.get_price();
    });
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

int MedService::getRecipeSize() const
{
    return static_cast<int>(recipe.size());
}

const vector<const Medicine *> &MedService::getRecipe() const
{
    return recipe;
}

void MedService::generateRecipe(int n)
{
    recipe.clear();

    const auto& allMeds = repo.getAll();

    if (n > static_cast<int>(allMeds.size()))
    {
        throw ServiceException("Not enough medicines!\n");
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

void MedService::exportCSV(const string &fileName) const
{
    std::ofstream out(fileName);

    for (const auto& med : recipe)
    {
        out << med->get_name() << ","
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
            << med->get_name()
            << " "
            << med->get_price()
            << " "
            << med->get_producer()
            << " "
            << med->get_active_substance()
            << "</p>";
    }

    out << "</body></html>";
}


void MedService::undo()
{
    if (undoActions.empty())
    {
        throw ServiceException("No more undo!");
    }
        UndoAction* act = undoActions.back();
        act->doUndo();
        undoActions.pop_back();
        delete act;
}

MedService::~MedService()
{
    for (auto& act: undoActions) // nu se copiaza pointerul
    {
        delete act;
    }
}



