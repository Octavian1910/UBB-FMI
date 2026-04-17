#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstdio>
#include "../domain/Medicine.h"
#include "../domain/Validator/ValidatorException.h"
#include "../Repository/MedRepository.h"
#include "../Repository/RepositoryException.h"
#include "../Service/MedService.h"

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

void testRepository()
{
    MedRepository repo;
    Medicine m1{"Nurofen", 200, "Reckitt", "Ibuprofen"};
    Medicine m2{"Paracetamol", 30, "Terapia", "Paracetamol"};
    Medicine m3{"Augmentin", 40, "GSK", "Amoxicilina"};
    Medicine m4{"Claritine", 50, "Bayer", "Loratadina"};
    Medicine m5{"Omez", 60, "Dr. Reddy", "Omeprazol"};

    //store and get all
    repo.store(m1);
    assert(repo.size() == 1);
    repo.store(m2);
    assert(repo.size() == 2);
    repo.store(m3);
    repo.store(m4);
    repo.store(m5);

    try
    {
        repo.store(m1);
        assert(false);
    }
    catch (RepositoryException& e)
    {
        assert(e.getMessage() == "Medicine already exist and cant be added!\n");
        assert(true);
    }

    assert(repo.size() == 5);

    try
    {
        repo.store(m5);
        assert(false);
    }
    catch (RepositoryException& e)
    {
        assert(e.getMessage() == "Medicine already exist and cant be added!\n");
        assert(true);
    }

    assert(repo.size() == 5);


    const vector<Medicine>& meds = repo.getAll();
    assert(meds.size() == 5);

    //remove
    string id = "Nurofen|Reckitt";
    repo.remove(id);

    const vector<Medicine>& meds2 = repo.getAll();
    assert(meds2.size() == 4);

    try
    {
        repo.remove(id);
        assert(false);
    }
    catch (RepositoryException& )
    {
        assert(true);
    }


    //find by id
    try
    {
        string id_temp="Random";
        auto& med = repo.find(id_temp);
        (void) med;
        assert(false);
    }
    catch (RepositoryException& )
    {
        assert(true);
    }

    //update
    Medicine m2_updated{"Paracetamol", 123, "Terapia", "Updated"};
    try
    {
        repo.update(m2_updated); //change price and ative substance

        const auto& find1 = repo.find("Paracetamol|Terapia");

        assert(find1.get_price() == 123);
        assert(find1.get_active_substance() == "Updated");
    }
    catch (RepositoryException& )
    {
         assert(false);
    }

    try
    {
        Medicine m_not_in_repo{"Random", 123, "Terapia", "Updated"};
        repo.update(m_not_in_repo);
        assert(false);
    }
    catch (RepositoryException& )
    {
        assert(true);
    }
}

void testService()
{
    MedRepository repository;
    MedValidator validator;
    MedService service{repository,validator};

    //store
    service.store("Nurofen", 200, "Reckitt", "Ibuprofen");
    service.store("Paracetamol", 30, "Terapia", "Paracetamol");
    service.store("Augmentin", 40, "GSK", "Amoxicilina");
    service.store("Omez", 60, "Dr. Reddy", "Omeprazol");

    assert(service.size() == 4);

    //find ok
    const auto& m = service.find("Nurofen|Reckitt");
    assert(m.get_price() == 200);

    //find exceptie
    try
    {
        auto& med = service.find("random");
        (void)med;
        assert(false);
    }
    catch (RepositoryException&)
    {
        assert(true);
    }

    //update ok
    service.update("Nurofen",150,"Reckitt","Updated");
    const auto& m2 = service.find("Nurofen|Reckitt");
    assert(m2.get_price() == 150);
    assert(m2.get_active_substance() == "Updated");

    //update exceptie
    try
    {
        service.update("Random",10,"R","X");
        assert(false);
    }
    catch (RepositoryException&)
    {
        assert(true);
    }

    //remove ok
    service.remove("Omez|Dr. Reddy");
    assert(service.size() == 3);

    //remove exceptie
    try
    {
        service.remove("Omez|Dr. Reddy");
        assert(false);
    }
    catch (RepositoryException&)
    {
        assert(true);
    }

    //validator exceptie
    try
    {
        service.store("",-1,"","");
        assert(false);
    }
    catch (ValidatorException&)
    {
        assert(true);
    }

    //get all
    const auto& rezz = service.getAll();
    assert(rezz.size() == 3);

    //filter by price
    auto rez1 = service.filterByPrice(50);
    bool gasit = false;
    for (const auto* med : rez1)
    {
        if (med->get_price() <= 50)
            gasit = true;
    }
    assert(gasit == true);

    auto rez2 = service.filterByPrice(10);
    assert(rez2.empty());

    //filter by substance
    auto rez3 = service.filterBySubstance("Paracetamol");
    assert(rez3.size() == 1);
    assert(rez3[0]->get_name() == "Paracetamol");

    auto rez4 = service.filterBySubstance("Random");
    assert(rez4.empty());

    //filter generic
    auto rez5 = service.filter([](const Medicine& med){
        return med.get_price() > 100;
    });
    assert(rez5.size() == 1);

    service.store("Same", 100, "SameProd", "SameSub");
    service.store("Same", 50, "SameProd1", "SameSub");
    service.store("Same1", 50, "SameProd", "SameSub");

    //sort by name asc
    auto s1 = service.sortByName(true);
    for (int i = 0; i < static_cast<int>(s1.size()) - 1; i++)
    {
        if (s1[i]->get_name() == s1[i+1]->get_name())
            assert(s1[i]->get_price() <= s1[i+1]->get_price());
        else
            assert(s1[i]->get_name() <= s1[i+1]->get_name());
    }

    //sort by name desc
    auto s2 = service.sortByName(false);
    for (int i = 0; i < static_cast<int>(s2.size()) - 1; i++)
    {
        if (s2[i]->get_name() == s2[i+1]->get_name())
            assert(s2[i]->get_price() >= s2[i+1]->get_price());
        else
            assert(s2[i]->get_name() >= s2[i+1]->get_name());
    }

    //sort by producer asc
    auto s3 = service.sortByProducer(true);
    for (int i = 0; i < static_cast<int>(s3.size()) - 1; i++)
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



void testAll()
{
    testDomain();
    printf("Domain\n");
    testRepository();
    printf("Repo\n");
    testService();
    printf("Service\n");
    printf("All test have passed!\n");
}