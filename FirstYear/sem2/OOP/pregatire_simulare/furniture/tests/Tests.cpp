//
// Created by octav on 22.05.2026.
//

#include "Tests.h"
#include <iostream>
#include <assert.h>
#include <fstream>

#include "../Domain/Furniture.h"
#include "../Domain/Validator/Validator.h"
#include "../Repository/Repository.h"
#include "../Service/Service.h"
using std::cout;

void test_domain()
{
    //id,type,nr_pieces,time
    Furniture f(1,"bed",102,12);
    assert(f.get_id() == 1);
    assert(f.get_type() == "bed");
    assert(f.get_nr_pieces() == 102);
    assert(f.get_time() == 12);
}

void test_validator()
{
    //id,type,nr_pieces,time
    Furniture f(1,"be",102,12);
    try
    {
        Validator validator;
        validator.validate(f);
        assert(false);
    }
    catch (std::runtime_error& e)
    {
        assert(string (e.what()) == "Type is not good!");
    }
}


void test_repository()
{
    string fisier = "test.txt";
    Repository repository(fisier);
    //cout<<repository.get_all().size();
    assert(repository.get_all().size() == 10);
    Furniture f(11,"bed",102,12);
    repository.add(f);
    assert(repository.get_all().size() == 11);
    try
    {
        Furniture invalid(1,"be",102,12);
        repository.add(invalid);
        assert(false);
    }catch (std::runtime_error& e)
    {
        assert(true);
    }
    assert(repository.get_all().size() == 11);


}



void setUp()
{
    std::string fisier = "test.txt";
    std::ofstream file(fisier);

    file << "1,nightstand,12,30\n";
    file << "2,bed,45,180\n";
    file << "3,table,20,75\n";
    file << "4,wardrobe,60,240\n";
    file << "5,nightstand,8,25\n";
    file << "6,bed,50,200\n";
    file << "7,table,16,60\n";
    file << "8,wardrobe,72,300\n";
    file << "9,nightstand,10,35\n";
    file << "10,table,24,90\n";
}



void test_service()
{
    std::string fisier = "test.txt";
    Repository repository(fisier);
    Service service(repository);

    assert(service.get_all().size() == 10);

    service.add(11, "bed", 100, 50);
    assert(service.get_all().size() == 11);

    std::vector<bool> checked = {true, false, false, false};
    auto filtered = service.filter_by_types(checked);

    assert(filtered.size() == 3);
    for (const auto& f : filtered)
    {
        assert(f.get_type() == "nightstand");
    }

    std::vector<bool> none_checked = {false, false, false, false};
    auto all = service.filter_by_types(none_checked);
    assert(all.size() == 11);

    auto sorted_pieces = service.sort_by_nr_pieces();
    for (int i = 0; i < sorted_pieces.size() - 1; i++)
    {
        assert(sorted_pieces[i].get_nr_pieces() <= sorted_pieces[i + 1].get_nr_pieces());
    }

    auto sorted_time = service.sort_by_time();
    for (int i = 0; i < sorted_time.size() - 1; i++)
    {
        assert(sorted_time[i].get_time() <= sorted_time[i + 1].get_time());
    }
}

void Tests::run_all()
{
    test_domain();
    test_validator();
    setUp();
    test_repository();
    setUp();
    test_service();
    cout<<"All tests have passsed!";
}
