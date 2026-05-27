//
// Created by octav on 22.05.2026.
//

#include "Tests.h"
#include <iostream>
#include <assert.h>

#include "../Domain/Postare.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
using std::cout;

void test_domain()
{
    //int cod,string creator,string tip,string platforma
    Postare p(1,"Ana","Reel","Instagram");
    assert(p.get_cod() == 1);
    assert(p.get_creator() == "Ana");
    assert(p.get_tip() == "Reel");
    assert(p.get_platforma() == "Instagram");
}

void test_repository()
{
    string fisier = "test_postari.txt";
    Repository repository(fisier);
    assert(repository.get_all().size() == 10);
}

void test_service()
{
    string fisier = "test_postari.txt";
    Repository repository(fisier);
    Service service(repository);
    assert(service.get_all().size() == 10);
    bool ascending = true;
    assert(service.sort_by_creator(ascending).at(0).get_cod() == 9);
    assert(service.sort_by_creator(!ascending).at(0).get_cod() == 10);
    assert(service.sort_by_platform(ascending).at(0).get_platforma() == "Instagram");
    assert(service.sort_by_platform(!ascending).at(0).get_platforma() == "Youtube Shorts");
}


void Tests::run_all()
{
    test_domain();
    test_repository();
    test_service();
    cout<<"All tests have passed!";
}
