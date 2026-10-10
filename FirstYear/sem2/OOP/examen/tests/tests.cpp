#include "tests.h"

#include "Melodie.h"
#include <iostream>
#include <assert.h>
#include <fstream>

#include "../repository/MelodieRepository.h"
#include "../repository/RepositoryException.h"
#include "../Service/MelodieService.h"
#include "../Service/ServiceException.h"
#include "validator/ValidatorException.h"
#include "validator/ValidatorMelodie.h"

void testDomain()
{
    Melodie m(1,"octa","eu",2);
    assert(m.get_ID() == 1);
    assert(m.get_title() == "octa");
    assert(m.get_artist() == "eu");
    assert(m.get_rank() == 2);

    m.set_artist("lol");
    m.set_rank(5);
    m.set_title("bau");
    assert(m.get_title() == "bau");
    assert(m.get_artist() == "lol");
    assert(m.get_rank() == 5);

}

void testValidator()
{
    Melodie valid(1,"octa","eu",2);
    try
    {
        ValidatorMelodie::validate(valid);
        assert(true);
    }catch (ValidatorException& )
    {
        assert(false);
    }

    Melodie invalid(-5,"","",-5);
    try
    {
        ValidatorMelodie::validate(invalid);
        assert(false);
    }catch (ValidatorException& e)
    {
        //std::cout << e.getMessage();
        assert(e.getMessage() == "ID ul trb sa fie mai mare decat 0!\nTitlul trb completat!\nArtistul trb completat!\nRankul trb sa fie intre 0 si 10!\n");
    }
}

void testRepository()
{
    std::ofstream out("test_melodii.txt");
    out << "1,Titlu,Octa,8\n";
    out << "2,Nume,Ari,10\n";
    out << "3,Dragon,Vlad,7\n";
    out.close();

    MelodieRepository repo{"test_melodii.txt"};
    assert(repo.getAll().size() == 3);
    const Melodie& m1 = repo.find(1);
    assert(m1.get_ID() == 1);
    assert(m1.get_title() == "Titlu");
    assert(m1.get_artist() == "Octa");

    try
    {
        repo.find(100);
        assert(false);
    }catch (RepositoryException&)
    {
        assert(true);
    }

    Melodie updated{1,"Updated","Lol",9};
    repo.update(updated);
    const Melodie& m1_updated = repo.find(1);
    assert(m1_updated.get_artist() == "Lol");
    assert(m1_updated.get_rank() == 9);
    assert(m1_updated.get_title() == "Updated");

    try
    {
        Melodie invalid{100,"no","idk",2};
        repo.update(invalid);
        assert(false);
    }catch (RepositoryException&)
    {
        assert(true);
    }
    std::remove("test_melodii.txt");
}

void testService()
{
    std::ofstream out("test_service_melodii.txt");
    out << "1,Caine,Octa,8\n";
    out << "2,Pisica,Bobi,10\n";
    out << "3,Lamaie,Octas,7\n";
    out << "4,Limonada,Bobi,10\n";
    out << "5,Vorbeste vinul,Octa,8\n";
    out.close();

    MelodieRepository repo{"test_service_melodii.txt"};
    ValidatorMelodie validator;
    MelodieService serv{repo,validator};

    assert(serv.getAllSorted().size()==5);

    const Melodie& m=serv.find(1);
    assert(m.get_title()=="Caine");

    auto all=serv.getAllSorted();

    for(int i = 0; i < all.size() - 1; i++)
        assert(all[i].get_rank() <= all[i+1].get_rank());

    try
    {
        serv.update(1,"Rau",20);
        assert(false);
    }
    catch(ValidatorException&)
    {
        assert(true);
    }

    serv.update(1,"Updated",5);
    //std::cout << serv.find(1).get_title();
    assert(serv.find(1).get_title()=="Updated");
    assert(serv.find(1).get_rank()==5);

    assert(serv.countRank(10)==2);

    serv.remove(2);
    assert(serv.getAllSorted().size()==4);

    try
    {
        serv.remove(4);
        assert(false);
    }
    catch(ServiceException&)
    {
        assert(true);
    }

    try
    {
        serv.remove(100);
        assert(false);
    }
    catch(RepositoryException&)
    {
        assert(true);
    }

    remove("test_service_melodii.txt");
}

void tests::runAll()
{
    testDomain();
    testValidator();
    testRepository();
    testService();
    std::cout << "Testele au rulat cu succes!";
}