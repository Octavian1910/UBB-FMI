//
// Created by octav on 01.04.2026.
//

#ifndef LAB4_MEDSERVICE_H
#define LAB4_MEDSERVICE_H
#include <vector>
#include <functional>
#include "../domain/Medicine.h"
#include "../domain/Validator/MedValidator.h"
#include "../Repository/MedRepository.h"
#include "../Repository/RepositoryException.h"
using std::function;

using std::vector;

class MedService
{
private:
    /*
     * reference to repository (stores medicines)
     */
    MedRepository& repo;

    /*
     * reference to validator (checks data)
     */
    MedValidator& validator;

public:
    /*
     * Creates service
     * :param rep: repository reference
     * :param validator: validator reference
     */
    MedService(MedRepository& rep,MedValidator& validator): repo(rep),validator(validator){}

    /*
     * disables copy constructor
     */
    MedService(const MedService& ot) = delete;

    /*
     * Adds a medicine
     * :param name: medicine name
     * :param price: medicine price
     * :param producer: producer
     * :param substance: active substance
     */
    void store(const string& name,int price,const string& producer,const string& substance) const;

    /*
     * Gets all medicines
     * :return: vector of medicines
     */
    const vector<Medicine>& getAll() const;

    /*
     * Removes a medicine
     * :param id: medicine id (name|producer)
     */
    void remove(const string& id) const;

    /*
     * Updates a medicine
     * :param name: medicine name
     * :param price: new price
     * :param producer: producer
     * :param substance: active substance
     */
    void update(const string& name,int price,const string& producer,const string& substance) const;

    /*
     * Finds a medicine
     * :param id: medicine id
     * :return: reference to medicine
     */
    const Medicine& find(const string& id) const;

    /*
     * Gets number of medicines
     * :return: size
     */
    int size() const;

    /*
     * Filters medicines using a condition
     * :param f: function that returns true or false
     * :return: filtered list
     */
    vector<Medicine> filter(function<bool(const Medicine&)> f) const;

    /*
     * Filters medicines by price
     * :param price: maximum price
     * :return: filtered list
     */
    vector<Medicine> filterByPrice(int price) const;

    /*
     * Filters medicines by active substance
     * :param substance: substance to match
     * :return: filtered list
     */
    vector<Medicine> filterBySubstance(const string& substance) const;

    /*
     * Sorts medicines using comparator
     * :param cmp: compare function
     * :return: sorted list
     */
    vector<Medicine> sort(function<bool(const Medicine&,const Medicine&)> cmp) const;

    /*
     * Sorts by name
     * :param ascending: true for asc, false for desc
     * :return: sorted list
     */
    vector<Medicine> sortByName(bool ascending) const;

    /*
     * Sorts by producer
     * :param ascending: true for asc, false for desc
     * :return: sorted list
     */
    vector<Medicine> sortByProducer(bool ascending) const;

    /*
     * Sorts by active substance
     * :param ascending: true for asc, false for desc
     * :return: sorted list
     */
    vector<Medicine> sortByActiveSubstance(bool ascending) const;
};


#endif //LAB4_MEDSERVICE_H