//
// Created by octav on 20.05.2026.
//

#include "Tests.h"
#include <assert.h>
#include <iostream>

#include "../domain/Skirt.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
using std::cout;


void testDomain()
{
    Skirt skirt(1,"gucci","s",100,false);
    assert(skirt.get_ID() == 1);
    assert(skirt.get_price() == 100);
    assert(skirt.get_size() == "s");
    assert(skirt.get_availability() == false);
    skirt.set_availability(true);
    assert(skirt.get_availability() == true);
}

void testRepository()
{
    string file_path = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_examen_2\\testSkirts.txt";
    Repository repo(file_path);
    //get all
    assert(repo.get_all().size() == 2);
    Skirt skirt = repo.get_all().at(0);
    assert(skirt.get_ID() == 1);
    skirt = repo.get_all().at(1);
    assert(skirt.get_ID() == 2);

    //find by id
    Skirt& result = repo.find_by_ID(1);
    assert(result.get_ID() == 1);
    assert(result.get_availability() == 1);
    assert(result.get_name() == "gucci");
}

void testService() {
    string file_path = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_examen_2\\testSkirts.txt";
    Repository repo(file_path);
    Service service{repo};
    auto sortedByPrice = service.sortSkirtsByPrice();
    assert(sortedByPrice.at(0).get_ID()==2);
    assert(sortedByPrice.at(1).get_ID()==1);
    auto sortedBySize = service.sortSkirtsBySize();
    assert(sortedBySize.at(0).get_ID()==2);
    assert(sortedBySize.at(1).get_ID()==1);
}

void Tests::runAll()
{
    testDomain();
    testRepository();
    testService();
    cout << "All tests have passed!";
}
