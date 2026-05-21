//
// Created by octav on 01.05.2026.
//

#include "tests.h"
#include <iostream>
#include <cassert>

#include "../domain/Medicine.h"
#include "../domain/validator/ValidatorException.h"
#include "../domain/validator/ValidatorMedicine.h"
#include "../repository/MedRepository.h"
#include "../repository/RepositoryException.h"
#include "../Service/MedService.h"
#include "../Service/ServiceException.h"
using std::cout;

void testDomain()
{
    //Medicament : denumire,pret,producator,substanta activa
    Medicine m1{"Nurofen", 200, "Reckitt", "Ibuprofen"};
    Medicine m2{"Paracetamol", 30, "Terapia", "Paracetamol"};

    assert(m1.get_name() == "Nurofen");
    assert(m1.get_producer() == "Reckitt");
    assert(m1.get_active_substance() == "Ibuprofen");
    assert(m1.get_price() == 200);
    assert(m1.get_ID() == "Nurofen|Reckitt");

    m1.set_name("Paracetamol");
    m1.set_price(30);
    m1.set_producer("Terapia");
    m1.set_active_substance("Paracetamol");

    assert(m1.get_name() == m2.get_name());
    assert(m1.get_producer() == m2.get_producer());
    assert(m1.get_active_substance() == m2.get_active_substance());
    assert(m1.get_price() == m2.get_price());

    //m1.set_active_substance("Paracetamol");;

}

void testValidator()
{
    Medicine m1{"Nurofen", 200, "Reckitt", "Ibuprofen"};
    try
    {
        ValidatorMedicine::validate(m1);
        assert(true);
    }catch (ValidatorException&)
    {
        assert(false);
    }
    Medicine m_invalid{"", -200, "", ""};
    try
    {
        ValidatorMedicine::validate(m_invalid);
        assert(false);
    }catch (ValidatorException&)
    {
        assert(true);
    }


}

void testRepostiory()
{
    MedRepository repo;
    Medicine m1{"Nurofen", 200, "Reckitt", "Ibuprofen"};
    Medicine m2{"Paracetamol", 30, "Terapia", "Paracetamol"};
    Medicine m3{"Augmentin", 40, "GSK", "Amoxicilina"};
    Medicine m4{"Claritine", 50, "Bayer", "Loratadina"};
    Medicine m5{"Omez", 60, "Dr. Reddy", "Omeprazol"};
    repo.store(m1);
    assert(repo.size() == 1);
    repo.store(m2);
    repo.store(m3);
    assert(repo.size() == 3);
    try
    {
        repo.store(m1);
        assert(false);
    }
    catch (RepositoryException&)
    {
        assert(true);
    }
    repo.store(m4);
    repo.store(m5);
    auto & rez = repo.getAll();
    assert(static_cast<size_t>(rez.size()) == static_cast<size_t>(repo.size()) and repo.size() == 5);

    Medicine m1_updated{"Nurofen", 500, "Reckitt", "Idk"};
    try
    {
        repo.update(m1_updated);
        assert(true);
    }catch (RepositoryException&)
    {
        assert(false);
    }

    Medicine m_invalid{"Nuro", 500, "Rec", "Idk"};
    try
    {
        repo.update(m_invalid);
        assert(false);
    }catch (RepositoryException& e)
    {
        assert(e.getMessage() == "Medicine doesnt exist and cant be updated!\n");
    }

    repo.remove(m1.get_ID()); // la remove se foloseste copy assignment
    assert(repo.size() == 4);
    try
    {
        repo.remove(m1.get_ID());
        assert(false);
    }catch (RepositoryException&)
    {
        assert(true);
    }

    const Medicine& m = repo.find(m2.get_ID());
    assert(m.get_ID() == m2.get_ID());
    try
    {
        (void)repo.find(m1.get_ID());
        assert(false);
    }catch (RepositoryException&)
    {
        assert(true);
    }
}

void testService()
{
    MedRepository repo;
    ValidatorMedicine validator;
    MedService service(repo,validator);

    //store
    service.store("Nurofen", 200, "Reckitt", "Ibuprofen");
    service.store("Paracetamol", 30, "Terapia", "Paracetamol");
    service.store("Augmentin", 40, "GSK", "Amoxicilina");
    service.store("Omez", 60, "Dr. Reddy", "Omeprazol");

    assert(service.size() == 4);

    //store invalid
    try
    {
        service.store("Nurofen", 200, "Reckitt", "Ibuprofen");
        assert(false);
    }catch (RepositoryException&)
    {
        assert(true);
    }

    //find ok
    const Medicine& m = service.find("Nurofen|Reckitt");
    assert(m.get_ID() == "Nurofen|Reckitt");
    //find invalid
    try
    {
        (void)service.find("Doesnt exist!");
        assert(false);
    }catch (RepositoryException&)
    {
        assert(true);
    }

    //update
    service.update("Nurofen", 150, "Reckitt", "Updated");
    const Medicine& med1 = service.find("Nurofen|Reckitt");
    assert(med1.get_price() == 150);
    assert(med1.get_active_substance() == "Updated");

    const vector<Medicine>& list = service.getAll();
    assert(static_cast<size_t>(list.size()) == static_cast<size_t>(service.size()));

    service.remove("Nurofen|Reckitt");
    assert(service.size() == 3);


    //filtrari

    //by price
    auto rez1 = service.filterByPrice(50);
    bool ok = true;
    for (const auto* med : rez1)
    {
        if (med->get_price() > 50)
            ok = false;
    }
    assert(ok == true);

    //by substance
    auto rez2 = service.filterBySubstance("Paracetamol");
    ok = true;
    for (const auto* med : rez1)
    {
        if (med->get_active_substance() > "Paracetamol")
            ok = false;
    }
    assert(ok == true);

    //sortari
    service.store("Same", 100, "SameProd", "SameSub");
    service.store("Same", 50, "SameProd1", "SameSub");
    service.store("Same1", 50, "SameProd", "SameSub");

    //sort by name crescator
    auto s1 = service.sortByName(true);
    for (int i = 0; i < static_cast<int>(s1.size() - 1) ; ++i)
    {
        if (s1[i]->get_name() == s1[i+1]->get_name())
            assert(s1[i]->get_price() <= s1[i+1]->get_price());
        else
           assert(s1[i]->get_name() <= s1[i+1]->get_name());
    }

    //sort by name descrescator
    auto s2 = service.sortByName(false);
    for (int i = 0; i < static_cast<int>(s2.size() - 1) ; ++i)
    {
        if (s2[i]->get_name() == s2[i+1]->get_name())
            assert(s2[i]->get_price() >= s2[i+1]->get_price());
        else
            assert(s2[i]->get_name() >= s2[i+1]->get_name());
    }

    //sort by producer cresc
    auto s3 = service.sortByProducer(true);
    for (int i = 0; i < static_cast<int>(s3.size() - 1) ; ++i)
    {
        if (s3[i]->get_producer() == s3[i+1]->get_producer())
            assert(s3[i]->get_price() <= s3[i+1]->get_price());
        else
            assert(s3[i]->get_producer() <= s3[i+1]->get_producer());
    }

    //sort by producer desc
    auto s4 = service.sortByProducer(false);
    for (int i = 0; i < static_cast<int>(s4.size()) - 1; i++)
    {
        if (s4[i]->get_producer() == s4[i+1]->get_producer())
            assert(s4[i]->get_price() >= s4[i+1]->get_price());
        else
            assert(s4[i]->get_producer() >= s4[i+1]->get_producer());
    }

    //sort by substance asc
    auto s5 = service.sortByActiveSubstance(true);
    for (int i = 0; i < static_cast<int>(s5.size()) - 1; i++)
    {
        if (s5[i]->get_active_substance() == s5[i+1]->get_active_substance())
            assert(s5[i]->get_price() <= s5[i+1]->get_price());
        else
            assert(s5[i]->get_active_substance() <= s5[i+1]->get_active_substance());
    }

    //sort by substance desc
    auto s6 = service.sortByActiveSubstance(false);
    for (int i = 0; i < static_cast<int>(s6.size()) - 1; i++)
    {
        if (s6[i]->get_active_substance() == s6[i+1]->get_active_substance())
            assert(s6[i]->get_price() >= s6[i+1]->get_price());
        else
            assert(s6[i]->get_active_substance() >= s6[i+1]->get_active_substance());
    }

}

void testRecipe()
{
    MedRepository repo;
    ValidatorMedicine validator;
    MedService service{repo,validator};

    service.store("Nurofen", 200, "Reckitt", "Ibuprofen");
    service.store("Paracetamol", 30, "Terapia", "Paracetamol");
    service.store("Augmentin", 40, "GSK", "Amoxicilina");

    assert(service.getRecipeSize() == 0);

    service.addToRecipe("Nurofen|Reckitt");
    const auto& rez = service.getRecipe();
    assert(rez.size() == 1);
    assert(service.getRecipeSize() == 1);

    service.clearRecipe();
    assert(service.getRecipeSize() == 0);

    service.generateRecipe(2);
    assert(service.getRecipeSize() == 2);

    service.clearRecipe();
    assert(service.getRecipeSize() == 0);

    try
    {
        service.generateRecipe(100);
        assert(false);
    }catch (ServiceException&)
    {
        assert(true);
    }

    try
    {
        service.addToRecipe("Nurofen|Reckitt1");
        assert(false);
    }catch (RepositoryException&)
    {
        assert(true);
    }

    service.addToRecipe("Nurofen|Reckitt");

    service.exportCSV("test.csv");


    FILE* f1 = fopen("test.csv", "r");
    assert(f1 != nullptr);

    fclose(f1);

    // export html
    service.exportHTML("test.html");

    FILE* f2 = fopen("test.html", "r");
    assert(f2 != nullptr);

    fclose(f2);

    // cleanup
    remove("test.csv");
    remove("test.html");



}

void tests::testAll()
{
    testDomain();
    testValidator();
    testRepostiory();
    testService();
    testRecipe();
    std::cout << "All tests passed successfully!";
}
