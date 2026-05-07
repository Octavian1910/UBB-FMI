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
     * medicines: all stored medicines
     */
    vector<Medicine> medicines;
public:
    /*
     * Creates repository
     */
    MedRepository() = default;

    /*
     * Copy constructor deleted
     */
    MedRepository(const MedRepository& ot) = delete;

    /*
     * Stores a medicine
     * :param med: medicine to store
     */
    void store(const Medicine& med);

    /*
     * Updates a medicine
     * :param med: updated medicine
     */
    void update(const Medicine& med);

    /*
     * Removes a medicine
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
     * :return: vector with medicines
     */
    const vector<Medicine>& getAll() const;

    /*
     * Finds a medicine
     * :param ID: medicine ID
     * :return: found medicine
     */
    const Medicine& find(const string& ID) const;
};


#endif //LAB5_IT1_REPOSITORYMED_H