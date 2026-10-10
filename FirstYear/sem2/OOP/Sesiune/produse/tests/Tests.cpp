//
// Created by octav on 27.06.2026.
//

#include "Tests.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include "../domain/Produs.h"
#include "../service/Service.h"
#include "../service/ServiceException.h"
#include "../repository/Repository.h"
#include "../repository/RepositoryException.h"
#include "../domain/validator/Validator.h"
#include "../domain/validator/ValidatorException.h"
using namespace std;
void testDomain()
{
    Produs p{1,"Laptop","Electronice",3500.5};

    assert(p.getId() == 1);
    assert(p.getNume() == "Laptop");
    assert(p.getTip() == "Electronice");
    assert(p.getPret() == 3500.5);

    p.setNume("Telefon");
    p.setTip("IT");
    p.setPret(2500);

    assert(p.getNume() == "Telefon");
    assert(p.getTip() == "IT");
    assert(p.getPret() == 2500);
}

void testValidator()
{
    {
        Produs p{1,"Laptop","Electronice",2500};
        Validator::validate(p);
    }

    {
        Produs p{1,"","",-10};

        try
        {
            Validator::validate(p);
            assert(false);
        }
        catch (ValidatorException& e)
        {
            assert(e.getMessage() ==
                   "Numele nu poate fi gol!\n"
                   "Tipul nu poate fi gol!\n"
                   "Pretul trebuie sa fie pozitiv!\n");
        }
    }
}


void testRepo()
{
    std::ofstream fout("test_repo.txt");

    fout << "1 Laptop Electronice 3500\n";
    fout << "2 Mouse Periferice 120\n";
    fout << "3 Tastatura Periferice 250\n";

    fout.close();

    Repository repo{"test_repo.txt"};

    const auto& all = repo.getAll();

    assert(all.size() == 3);
    assert(all[0].getId() == 1);
    assert(all[1].getId() == 2);
    assert(all[2].getId() == 3);

    {
        Produs p = repo.findById(2);

        assert(p.getId() == 2);
        assert(p.getNume() == "Mouse");
        assert(p.getTip() == "Periferice");
        assert(p.getPret() == 120);
    }

    {
        Produs p{4,"Monitor","Electronice",1500};

        repo.add(p);

        assert(repo.getAll().size() == 4);

        Produs gasit = repo.findById(4);

        assert(gasit.getId() == 4);
        assert(gasit.getNume() == "Monitor");
        assert(gasit.getTip() == "Electronice");
        assert(gasit.getPret() == 1500);
    }

    {
        try
        {
            Produs p{4,"TV","Electronice",3000};

            repo.add(p);

            assert(false);
        }
        catch (RepositoryException&)
        {
            assert(true);
        }
    }

    {
        Produs p{2,"MouseGaming","Gaming",300};

        repo.update(p);

        Produs modificat = repo.findById(2);

        assert(modificat.getNume() == "MouseGaming");
        assert(modificat.getTip() == "Gaming");
        assert(modificat.getPret() == 300);
    }

    {
        try
        {
            Produs p{100,"AAA","BBB",10};

            repo.update(p);

            assert(false);
        }
        catch (RepositoryException&)
        {
            assert(true);
        }
    }
}

void testService()
{
    std::ofstream fout("test_service.txt");

    fout << "1 Laptop Electronice 80\n";
    fout << "2 Mouse Periferice 20\n";
    fout << "3 Monitor Electronice 50\n";

    fout.close();

    Repository repo{"test_service.txt"};
    Validator val;
    Service serv{repo,val};

    {
        Produs p = serv.findById(1);

        assert(p.getId() == 1);
        assert(p.getNume() == "Laptop");
        assert(p.getTip() == "Electronice");
        assert(p.getPret() == 80);
    }

    {
        auto produse = serv.getAllSorted();

        assert(produse.size() == 3);

        assert(produse[0].getPret() == 20);
        assert(produse[1].getPret() == 50);
        assert(produse[2].getPret() == 80);
    }

    {
        serv.addProdus(4,"Boxa","Audio",35);

        Produs p = serv.findById(4);

        assert(p.getId() == 4);
        assert(p.getNume() == "Boxa");
        assert(p.getTip() == "Audio");
        assert(p.getPret() == 35);
    }

    {
        serv.updateProdus(4,"BoxaPro","Audio",45);

        Produs p = serv.findById(4);

        assert(p.getNume() == "BoxaPro");
        assert(p.getTip() == "Audio");
        assert(p.getPret() == 45);
    }

    {
        assert(serv.nrVocale("Laptop") == 2);
        assert(serv.nrVocale("Mouse") == 3);
        assert(serv.nrVocale("xyz") == 0);
    }

    {
        try
        {
            serv.addProdus(4,"TV","Electronice",90);
            assert(false);
        }
        catch (RepositoryException&)
        {
            assert(true);
        }
    }

    {
        try
        {
            serv.addProdus(5,"","Electronice",-5);
            assert(false);
        }
        catch (ValidatorException&)
        {
            assert(true);
        }
    }
}

void Tests::runAll()
{
    testDomain();
    testValidator();
    testRepo();
    testService();
    std::cout << "Toate testele au trecut cu succes!";
}
