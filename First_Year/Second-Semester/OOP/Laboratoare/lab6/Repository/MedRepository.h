//
// Created by octav on 01.04.2026.
//

#ifndef LAB4_MEDREPOSITORY_H
#define LAB4_MEDREPOSITORY_H
#include "../domain/Medicine.h"
#include <vector>
using std::vector;

class MedRepository
{
private:
    /*
     * stores all medicines
     */
    vector<Medicine> medicines;

public:
    /*
     * disables copy constructor
     */
    MedRepository(const Medicine& ot) = delete;

    /*
     * default constructor
     */
    MedRepository() = default;

    /*
     * Adds a medicine
     * :param med: medicine to add
     * :throws: RepositoryException if exists
     */
    void store(const Medicine& med);

    /*
     * Gets all medicines
     * :return: vector of medicines
     */
    [[nodiscard]] const vector<Medicine>& getAll() const;

    /*
     * Removes a medicine
     * :param id: medicine id
     * :throws: RepositoryException if not found
     */
    void remove(const string& id);

    /*
     * Updates a medicine
     * :param med: new medicine
     * :throws: RepositoryException if not found
     */
    void update(const Medicine &med);

    /*
     * Finds a medicine
     * :param id: medicine id
     * :return: reference to medicine
     * :throws: RepositoryException if not found
     */
    [[nodiscard]] const Medicine& find(const string& id) const;

    /*
     * Gets number of medicines
     * :return: size
     */
    [[nodiscard]] int size() const;
};


#endif //LAB4_MEDREPOSITORY_H