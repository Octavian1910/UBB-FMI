//
// Created by octav on 21.05.2026.
//

#include "Tests.h"
#include <iostream>
#include <fstream>
#include <assert.h>

#include "../Domain/Validator/Validator.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
using std::cout;

#include "../Domain/Radiation.h"

void test_domain()
{
    //radation(int id,string description,float frequency,string type_frequency)
    Radiation rad(1,"scanare echipament",55.3,"alpha");
    assert(rad.get_ID() == 1);
    assert(rad.get_description() == "scanare echipament");
    assert(rad.get_frequency() == 55.3f);
    assert(rad.get_type_frequency() == "alpha");
}

void test_validator_domain()
{
    Radiation invalid_rad(1,"",101.15,"gresit");
    Validator validator;
    try
    {
        validator.validate(invalid_rad);
    }
    catch (ValidatorException& e)
    {
        assert(e.getMessage() == "Invalid description!\n"
                    "Invalid frequency!\n"
                    "Invalid type!\n");
    }
}

void test_repository()
{
    string file = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_simulare\\radation\\cmake-build-debug\\test_frecventa.txt";
    Repository repo(file);
    //cout<<repo.get_all().size();
    assert(repo.get_all().size() == 10);
    assert(repo.get_all().at(0).get_ID() == 1);
    assert(repo.get_all().at(0).get_frequency() == 45.5f);
    Radiation rad(1,"scanare echipament",55.3,"alpha");
    repo.add(rad);
    assert(repo.get_all().size() == 11);
}

void test_service()
{
    string file = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_simulare\\radation\\cmake-build-debug\\test_frecventa.txt";
    Repository repo(file);
    Service service(repo);
    assert(service.filter_by_type_frequency("del").at(0).get_ID() == 4);
    assert(service.filter_by_frequency(25.4).size() == 4);
    assert(service.filter_for_ui(25.4,"del").size() == 1);
    try
    {
        service.add(1,"scanare echipament",55.3,"alpha");
        assert(true);
    }catch (...)
    {
        assert(false);
    }
    assert(service.get_all().size() == 11);
    try
    {
        service.add(1,"",101,"alp123ha");
        assert(false);
    }catch (...)
    {
        assert(true);
    }
    assert(service.get_all().size() == 11);
}

void rewrite_file_text()
{
    string path = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_simulare\\radation\\cmake-build-debug\\test_frecventa.txt";
    std::ofstream file(path);
    file << "1,masurare radiatii laborator,45.5,alpha\n";
    file << "2,control nivel radiatii,70,beta\n";
    file << "3,verificare reactor,90.2,gamma\n";
    file << "4,test camera izolare,30,delta\n";
    file << "5,monitorizare zona A,15.7,theta\n";
    file << "6,scanare echipament,55.3,alpha\n";
    file << "7,detectie sursa radiatii,82.1,beta\n";
    file << "8,masurare fundal natural,10,gamma\n";
    file << "9,control siguranta,25.4,delta\n";
    file << "10,verificare protectie,25.4,theta\n";

}

void Tests::test_all()
{

    test_domain();
    test_validator_domain();
    rewrite_file_text();
    test_repository();
    rewrite_file_text();
    test_service();
 cout<<"All tests have passed!";
}
