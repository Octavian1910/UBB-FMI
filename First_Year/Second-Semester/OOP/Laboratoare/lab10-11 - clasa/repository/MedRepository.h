#pragma once
#include <vector>
#include "../domain/Medicine.h"

using std::vector;

class MedRepository
{
private:
    /*
     * medicines: medicine repository
     */
    vector<Medicine> medicines;

public:
    /*
     * Default constructor
     */
    MedRepository() = default;

    /*
     * Copy constructor deleted
     */
    MedRepository(const MedRepository& ot) = delete;

    /*
     * Stores medicine
     * :param med: medicine to store
     */
    void store(const Medicine& med);

    /*
     * Updates medicine
     * :param med: updated medicine
     */
    void update(const Medicine& med);

    /*
     * Removes medicine
     * :param ID: medicine ID
     */
    void remove(const string& ID);

    /*
     * Gets repository size
     * :return: size
     */
    [[nodiscard]] int size() const;

    /*
     * Gets all medicines
     * :return: medicine vector
     */
    [[nodiscard]] const vector<Medicine>& getAll() const;

    /*
     * Finds medicine
     * :return: medicine
     */
    [[nodiscard]] const Medicine& find(const string& ID) const;
};