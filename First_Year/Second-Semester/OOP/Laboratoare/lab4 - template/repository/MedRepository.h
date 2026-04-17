//
// Created by octav on 17.04.2026.
//

#ifndef LAB4___TEMPLATE_MEDREPOSITORY_H
#define LAB4___TEMPLATE_MEDREPOSITORY_H
#include <string>

#include "MyVector.h"
#include "../domain/Medicine.h"
using std::string;

class MedRepository
{
private:
    MyVector<Medicine> medicines;
public:
    MedRepository() = default;

    void store(const Medicine& m);
    void remove(const string& id);
    void update(const Medicine& med);
    [[nodiscard]] const Medicine& find(const std::string& id) const;
    [[nodiscard]] const MyVector<Medicine>& getAll() const;
    [[nodiscard]] int size() const;
};


#endif //LAB4___TEMPLATE_MEDREPOSITORY_H