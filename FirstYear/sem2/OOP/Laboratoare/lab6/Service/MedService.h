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
    [[nodiscard]] const vector<Medicine>& getAll() const;

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
    [[nodiscard]] const Medicine& find(const string& id) const;

    /*
     * Gets number of medicines
     * :return: size
     */
    [[nodiscard]] int size() const;

    vector<const Medicine*> filter(const function<bool(const Medicine&)>& f) const;

    [[nodiscard]] vector<const Medicine*> filterByPrice(int price) const;
    [[nodiscard]] vector<const Medicine*> filterBySubstance(const string& substance) const;

    vector<const Medicine*> sort(function<bool(const Medicine&, const Medicine&)> cmp) const;

    [[nodiscard]] vector<const Medicine*> sortByName(bool ascending) const;
    [[nodiscard]] vector<const Medicine*> sortByProducer(bool ascending) const;
    [[nodiscard]] vector<const Medicine*> sortByActiveSubstance(bool ascending) const;
};


#endif //LAB4_MEDSERVICE_H