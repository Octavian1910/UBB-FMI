//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_REPOSITORYMED_H
#define LAB5_IT1_REPOSITORYMED_H
#include <vector>
#include "../domain/Medicine.h"

using std::vector;

class MedRepository
{
private:
    /*
     * medicines: vector that stores all medicines
     */
    vector<Medicine> medicines;

public:
    /*
     * Default constructor
     */
    MedRepository() = default;

    /*
     * Copy constructor deleted
     * :param ot: repository to copy
     */
    MedRepository(const MedRepository& ot) = delete;

    /*
     * Stores a medicine in repository
     * :param med: medicine to store
     */
    void store(const Medicine& med);

    /*
     * Updates a medicine from repository
     * :param med: updated medicine
     */
    void update(const Medicine& med);

    /*
     * Removes a medicine from repository
     * :param ID: medicine ID
     */
    void remove(const string& ID);

    /*
     * Gets repository size
     * :return: number of medicines
     */
    int size() const;

    /*
     * Gets all medicines
     * :return: vector of medicines
     */
    const vector<Medicine>& getAll() const;

    /*
     * Finds a medicine by ID
     * :param ID: medicine ID
     * :return: found medicine
     */
    const Medicine& find(const string& ID) const;
};

#endif //LAB5_IT1_REPOSITORYMED_H