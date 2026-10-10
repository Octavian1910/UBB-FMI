#pragma once
#include "../repository/MedRepository.h"
#include "../domain/validator/ValidatorMedicine.h"
#include "Undo/UndoAction.h"
#include "Observer.h"
#include <functional>

using std::function;

class MedService: public Observable
{
private:
    /*
     * recipe: recipe medicines
     * undoActions: undo operations
     * repo: repository reference
     * validator: validator reference
     */
    vector<const Medicine*> recipe;
    vector<UndoAction*> undoActions;
    MedRepository& repo;
    ValidatorMedicine& validator;

public:
    /*
     * Creates service
     * :param repo: repository reference
     * :param validator: validator reference
     */
    MedService(MedRepository& repo, ValidatorMedicine& validator)
        : repo{repo}, validator{validator} {}

    /*
     * Destructor
     */
    ~MedService();

    /*
     * Copy constructor deleted
     */
    MedService(const MedService& ot) = delete;

    /*
     * Stores medicine
     */
    void store(const string& name, int price, const string& producer, const string& active_substance);

    /*
     * Updates medicine
     */
    void update(const string& name, int price, const string& producer, const string& active_substance);

    /*
     * Removes medicine
     */
    void remove(const string& ID);

    /*
     * Gets all medicines
     * :return: medicine vector
     */
    [[nodiscard]] const vector<Medicine>& getAll() const;

    /*
     * Finds medicine by ID
     * :return: medicine
     */
    [[nodiscard]] const Medicine& find(const string& ID) const;

    /*
     * Gets repository size
     * :return: size
     */
    [[nodiscard]] int size() const;

    /*
     * Generic filter
     */
    vector<const Medicine*> filter(const function<bool(const Medicine&)>& f) const;

    /*
     * Filters by price
     */
    vector<const Medicine*> filterByPrice(int price) const;

    /*
     * Filters by substance
     */
    vector<const Medicine*> filterBySubstance(const string& active_substance) const;

    /*
     * Generic sort
     */
    vector<const Medicine*> sort(const function<bool(const Medicine&, const Medicine&)>& cmp) const;

    /*
     * Sorts by name
     */
    vector<const Medicine*> sortByName(bool ascending) const;

    /*
     * Sorts by producer
     */
    vector<const Medicine*> sortByProducer(bool ascending) const;

    /*
     * Sorts by active substance
     */
    vector<const Medicine*> sortByActiveSubstance(bool ascending) const;

    /*
     * Clears recipe
     */
    void clearRecipe();

    /*
     * Adds medicine to recipe
     */
    void addToRecipe(const string& ID);

    /*
     * Generates random recipe
     */
    void generateRecipe(int number);

    /*
     * Gets recipe
     * :return: recipe vector
     */
    [[nodiscard]] const vector<const Medicine*>& getRecipe() const;

    /*
     * Exports recipe to CSV
     */
    void exportCSV(const string& file_name) const;

    /*
     * Exports recipe to HTML
     */
    void exportHTML(const string& file_name) const;

    /*
     * Gets recipe size
     * :return: size
     */
    [[nodiscard]] int getRecipeSize() const;

    /*
     * Undo last operation
     */
    void undo();
};