//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_MEDSERVICE_H
#define LAB5_IT1_MEDSERVICE_H
#include "../repository/MedRepository.h"
#include "../domain/validator/ValidatorMedicine.h"
#include <functional>

using std::function;

class MedService
{
private:
    /*
     * recipe: recipe medicines
     * repo: medicine repository
     * validator: medicine validator
     */
    vector<const Medicine*> recipe;
    MedRepository& repo;
    ValidatorMedicine& validator;

public:
    /*
     * Creates service
     * :param repo: medicine repository
     * :param validator: medicine validator
     */
    MedService(MedRepository& repo, ValidatorMedicine& validator) : repo{repo}, validator{validator} {}

    /*
     * Copy constructor deleted
     * :param ot: service to copy
     */
    MedService(const MedService& ot) = delete;

    /*
     * Stores a medicine
     * :param name: medicine name
     * :param price: medicine price
     * :param producer: producer name
     * :param active_substance: active substance
     */
    void store(const string& name, int price, const string& producer, const string& active_substance) const;

    /*
     * Updates a medicine
     * :param name: medicine name
     * :param price: medicine price
     * :param producer: producer name
     * :param active_substance: active substance
     */
    void update(const string& name, int price, const string& producer, const string& active_substance) const;

    /*
     * Removes a medicine
     * :param ID: medicine ID
     */
    void remove(const string& ID) const;

    /*
     * Gets all medicines
     * :return: vector of medicines
     */
    const vector<Medicine>& getAll() const;

    /*
     * Finds a medicine
     * :param ID: medicine ID
     * :return: found medicine
     */
    const Medicine& find(const string& ID) const;

    /*
     * Gets repository size
     * :return: number of medicines
     */
    int size() const;

    /*
     * Generic filter
     * :param f: filtering function
     * :return: filtered medicines
     */
    vector<const Medicine*> filter(const function<bool(const Medicine&)>& f) const;

    /*
     * Filters medicines by price
     * :param price: target price
     * :return: filtered medicines
     */
    vector<const Medicine*> filterByPrice(int price) const;

    /*
     * Filters medicines by active substance
     * :param active_substance: target substance
     * :return: filtered medicines
     */
    vector<const Medicine*> filterBySubstance(const string& active_substance) const;

    /*
     * Generic sort
     * :param cmp: compare function
     * :return: sorted medicines
     */
    vector<const Medicine*> sort(const function<bool(const Medicine&, const Medicine&)>& cmp) const;

    /*
     * Sorts medicines by name
     * :param ascending: sorting order
     * :return: sorted medicines
     */
    vector<const Medicine*> sortByName(bool ascending) const;

    /*
     * Sorts medicines by producer
     * :param ascending: sorting order
     * :return: sorted medicines
     */
    vector<const Medicine*> sortByProducer(bool ascending) const;

    /*
     * Sorts medicines by active substance
     * :param ascending: sorting order
     * :return: sorted medicines
     */
    vector<const Medicine*> sortByActiveSubstance(bool ascending) const;

    /*
     * Clears recipe
     */
    void clearRecipe();

    /*
     * Adds medicine to recipe
     * :param ID: medicine ID
     */
    void addToRecipe(const string& ID);

    /*
     * Generates random recipe
     * :param number: number of medicines
     */
    void generateRecipe(int number);

    /*
     * Gets recipe
     * :return: recipe medicines
     */
    const vector<const Medicine*>& getRecipe() const;

    /*
     * Exports recipe to CSV
     * :param file_name: file name
     */
    void exportCSV(const string& file_name) const;

    /*
     * Exports recipe to HTML
     * :param file_name: file name
     */
    void exportHTML(const string& file_name) const;

    /*
     * Gets recipe size
     * :return: number of medicines
     */
    int getRecipeSize() const;
};

#endif //LAB5_IT1_MEDSERVICE_H