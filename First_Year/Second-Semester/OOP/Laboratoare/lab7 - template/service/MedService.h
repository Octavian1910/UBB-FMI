//
// Created by octav on 17.04.2026.
//

#ifndef LAB4___TEMPLATE_MEDSERVICE_H
#define LAB4___TEMPLATE_MEDSERVICE_H
#include "../domain/Medicine.h"
#include <string>

#include "../repository/MyVector.h"
#include "../repository/MedRepository.h"
#include "../domain/validator/MedValidator.h"

using std::string;

class MedService
{
private:
    MedRepository& repo;
    MedValidator& validator;

public:
    MedService(MedRepository& repo,MedValidator& validator):repo{repo},validator{validator}{};
    void store(const string& name,int price,const string& producer,const string& active_substance) const;
    void remove(const string& id) const;
    void update(const string& name,int price,const string& producer,const string& substance) const;

    [[nodiscard]] const Medicine& find(const string &id) const;
    [[nodiscard]] const MyVector<Medicine>& getAll() const;
    [[nodiscard]] int size() const;

    template<typename Func> //Funct poate sa fie orice functie
    MyVector<const Medicine*> filter(Func predicate) const { //predicate este o functie
        MyVector<const Medicine*> result;

        for (const Medicine& med : repo.getAll()) {
            if (predicate(med))
                result.add(&med);
        }

        return result;}
    /*tipul de return         nume    numele functiei   functia primeste o referinta la un medicament  */
    MyVector<const Medicine*> filterByPrice(int price) const;
    MyVector<const Medicine*> filterBySubstance(const string& active_substance) const;



    template<typename Func>
  MyVector<const Medicine*> sort(Func cmp) const {
        MyVector<const Medicine*> result;

        for (const Medicine& med : repo.getAll()) {
            result.add(&med);
        }

        for (int i = 0; i < result.getSize() - 1; i++) {
            for (int j = i + 1; j < result.getSize(); j++) {
                if (cmp(*result[j], *result[i])) {
                    const Medicine* aux = result[i];
                    result[i] = result[j];
                    result[j] = aux;
                }
            }
        }

        return result;}


    template<typename KeyFunc>
    MyVector<const Medicine*> sortBy(KeyFunc key, bool ascending) const {
        return sort([key, ascending](const Medicine& a, const Medicine& b) {

            if (key(a) == key(b)) {
                if (ascending)
                    return a.get_price() < b.get_price();
                else
                    return a.get_price() > b.get_price();
            }

            if (ascending)
                return key(a) < key(b);
            else
                return key(a) > key(b);
        });
    }

    MyVector<const Medicine*> sortByName(bool ascending) const;
    MyVector<const Medicine*> sortByProducer(bool ascending) const;
    MyVector<const Medicine*> sortByActiveSubstance(bool ascending) const;
};

#endif //LAB4___TEMPLATE_MEDSERVICE_H