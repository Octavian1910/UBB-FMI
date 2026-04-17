#include "tests.h"
#include <cassert>
#include <iostream>

#include "../domain/validator/MedValidator.h"
#include "../domain/validator/ValidatorException.h"
#include "../domain/Medicine.h"
#include "../repository/MedRepository.h"
#include "../repository/MyVector.h"
#include "../repository/RepositoryException.h"
#include "../service/MedService.h"

using std::cout;

void TestMedService::runAll() {
    testDomain(); // Testează settere și metode simple din Medicine
    testMyVectorExtra(); // Acoperire 100% pentru MyVector
    testStoreAndGetAll();
    testUpdate();
    testRemove();
    testFind();

    testFilterPrice();
    testFilterSubstance();

    testSortByName();
    testSortByProducer();
    testSortBySubstance();
    testSortEqualKey();

    testRepoExceptions();
    testValidatorExceptions();

    cout << "All tests passed with 100% coverage strategy!\n";
}

// Testăm metodele din Medicine care pot fi omise de testele de service
void TestMedService::testDomain() {
    Medicine m{"A", 10, "P1", "S1"};
    assert(m.get_name() == "A");
    assert(m.get_price() == 10);
    assert(m.get_producer() == "P1");
    assert(m.get_active_substance() == "S1");
    assert(m.get_ID() == "A|P1");

    m.set_name("B");
    m.set_price(20);
    m.set_producer("P2");
    m.set_active_substance("S2");
    assert(m.get_name() == "B");
    assert(m.get_price() == 20);
}

// Teste specifice pentru MyVector (Copy Constructor, Assignment, removeLast, Resize)
void TestMedService::testMyVectorExtra() {
    MyVector<int> v;
    v.add(1);
    v.add(2);
    v.add(3); // Provoacă resize dacă capacitatea inițială e 2

    // Test copy constructor
    MyVector<int> v2 = v;
    assert(v2.getSize() == 3);
    assert(v2[0] == 1);

    // Test assignment operator
    MyVector<int> v3;
    v3 = v;
    assert(v3.getSize() == 3);

    // Test self-assignment (pentru a acoperi if (this != &other))
    v3 = v3;
    assert(v3.getSize() == 3);

    // Test removeLast
    int last = v.removeLast();
    assert(last == 3);
    assert(v.getSize() == 2);

    // Test removeLast pe vector gol
    MyVector<int> emptyV;
    emptyV.removeLast();
    assert(emptyV.getSize() == 0);

    // Test iterator begin/end (const și non-const)
    auto it = v.begin();
    assert(*it == 1);
    const MyVector<int>& vConst = v;
    assert(*(vConst.begin()) == 1);
}

void TestMedService::testStoreAndGetAll() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "S1");
    srv.store("B", 20, "P2", "S2");

    assert(srv.size() == 2); // Testează și metoda size()
    const auto& all = srv.getAll();
    assert(all.getSize() == 2);
    assert(all[0].get_name() == "A");
}

void TestMedService::testUpdate() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "S1");
    srv.update("A", 50, "P1", "S1");

    const auto& med = srv.find("A|P1");
    assert(med.get_price() == 50);
}

void TestMedService::testRemove() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "S1");
    srv.remove("A|P1");

    assert(srv.getAll().getSize() == 0);
}

void TestMedService::testFind() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "S1");
    const auto& med = srv.find("A|P1");
    assert(med.get_name() == "A");
}

void TestMedService::testFilterPrice() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "S1");
    srv.store("B", 20, "P2", "S2");

    auto result = srv.filterByPrice(10);
    assert(result.getSize() == 1);
}

void TestMedService::testFilterSubstance() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "ibuprofen");
    auto result = srv.filterBySubstance("ibuprofen");
    assert(result.getSize() == 1);
}

void TestMedService::testSortByName() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("B", 10, "P1", "S1");
    srv.store("A", 20, "P2", "S2");

    auto sorted = srv.sortByName(true);
    assert(sorted[0]->get_name() == "A");

    auto sortedDesc = srv.sortByName(false);
    assert(sortedDesc[0]->get_name() == "B");
}

void TestMedService::testSortByProducer() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "Z", "s1");
    srv.store("B", 20, "A", "s2");

    auto sorted = srv.sortByProducer(true);
    assert(sorted[0]->get_producer() == "A");

    auto sortedDesc = srv.sortByProducer(false);
    assert(sortedDesc[0]->get_producer() == "Z");
}

void TestMedService::testSortBySubstance() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "b");
    srv.store("B", 20, "P2", "a");

    auto sorted = srv.sortByActiveSubstance(true);
    assert(sorted[0]->get_active_substance() == "a");

    auto sortedDesc = srv.sortByActiveSubstance(false);
    assert(sortedDesc[0]->get_active_substance() == "b");
}

void TestMedService::testSortEqualKey() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("Same", 30, "P1", "s1");
    srv.store("Same", 10, "P2", "s2");

    auto sorted = srv.sortByName(true);
    assert(sorted[0]->get_price() == 10); // Sortare secundară după preț

    auto sortedDesc = srv.sortByName(false);
    assert(sortedDesc[0]->get_price() == 30);
}

void TestMedService::testRepoExceptions() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    srv.store("A", 10, "P1", "S1");
    try {
        srv.store("A", 20, "P1", "S2");
        assert(false);
    } catch (RepositoryException&) { assert(true); }

    try {
        srv.remove("Inexistent");
        assert(false);
    } catch (RepositoryException&) { assert(true); }
}

void TestMedService::testValidatorExceptions() {
    MedRepository repo;
    MedValidator val;
    MedService srv{ repo, val };

    try {
        srv.store("", -1, "", "");
        assert(false);
    } catch (ValidatorException&) { assert(true); }
}