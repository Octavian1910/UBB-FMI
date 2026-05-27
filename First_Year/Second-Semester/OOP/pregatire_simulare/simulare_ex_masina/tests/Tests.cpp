//
// Created by octav on 21.05.2026.
//

#include "Tests.h"
#include <iostream>
#include <assert.h>
#include <vector>

#include "../domain/Car.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
using std::cout;

void testDomain()
{
    //Car(id,specie,nume,varsta)
    Car car(1,"Dacia","Logan",67);
    assert(car.get_ID() == 1);
    assert(car.get_brand() == "Dacia");
    assert(car.get_model() == "Logan");
    assert(car.get_age() == 67);
}

void testRepository()
{
    string file_path = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_simulare\\simulare_ex_masina\\tests_cars.txt";
    Repository repo(file_path);
    std::vector<Car> result = repo.get_all();
    assert( result.size() == 10);
    assert( result.at(0).get_ID() == 1);
    assert( result.at(0).get_brand() == "Dacia");
}

void testService()
{
    string file_path = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_simulare\\simulare_ex_masina\\tests_cars.txt";
    Repository repo(file_path);
    Service serv(repo);
    std::vector<Car> result = serv.filter_by_brand("Dacia");
    assert(result.size() == 3);
    bool ascending = true;
    result = serv.sort_by_age(ascending);
    assert(result.at(0).get_age() < result.at(1).get_age());
    bool descending = false;
    result = serv.sort_by_age(descending);
    assert(result.at(0).get_age() > result.at(1).get_age());
}

void Tests::runAll()
{
    testDomain();
    testRepository();
    testService();
    cout << "All tests have passed!";
}
