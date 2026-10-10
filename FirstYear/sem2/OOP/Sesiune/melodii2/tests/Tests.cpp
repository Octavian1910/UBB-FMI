#include "Tests.h"
#include "../domain/validator/Validator.h"
#include "../domain/validator/ValidatorException.h"
#include <assert.h>
#include <iostream>
#include <fstream>
#include "../domain/Melodie.h"
#include "../service/Service.h"
#include "../service/ServiceException.h"
#include "../repository/RepoException.h"
#include "../repository/Repo.h"
using std::cout;
using std::ofstream;

void testDomain()
{
    Melodie m{1,"Numb","Linkin Park","rock"};

    assert(m.getId() == 1);
    assert(m.getTitlu() == "Numb");
    assert(m.getArtist() == "Linkin Park");
    assert(m.getGen() == "rock");
}


void testValidator()
{
    Validator val;

    Melodie m1{1,"A","B","rock"};
    val.valideaza(m1);

    Melodie m2{2,"A","B","manele"};

    try
    {
        val.valideaza(m2);
        assert(false);
    }
    catch(const ValidatorException&)
    {
        assert(true);
    }
}


void createTestFile()
{
    ofstream fout("test.txt");

    fout << "1;Numb;Linkin Park;rock\n";
    fout << "2;Believer;Imagine Dragons;rock\n";
    fout << "3;Perfect;Ed Sheeran;pop\n";

    fout.close();
}


void testRepo()
{
    ofstream fout("test.txt");
    fout.close();

    Repo repo("test.txt");

    Melodie m1{1,"A","B","rock"};

    repo.add(m1);

    assert(repo.getAll().size() == 1);

    try
    {
        repo.add(m1);
        assert(false);
    }
    catch(const RepoException&)
    {
        assert(true);
    }

    repo.remove(1);

    assert(repo.getAll().empty());

    try
    {
        repo.remove(10);
        assert(false);
    }
    catch(const RepoException&)
    {
        assert(true);
    }
}


void testService()
{
    ofstream fout("test.txt");
    fout.close();

    Validator val;
    Repo repo("test.txt");

    Service srv(repo, val);

    srv.add("Numb", "Linkin Park", "rock");
    srv.add("Believer", "Imagine Dragons", "rock");
    srv.add("Perfect", "Ed Sheeran", "pop");

    assert(srv.getAll().size() == 3);

    assert(srv.getNrArtist("Linkin Park") == 1);
    assert(srv.getNrArtist("Imagine Dragons") == 1);
    assert(srv.getNrArtist("Ed Sheeran") == 1);

    auto v = srv.sortArtist();

    assert(v[0].getArtist() == "Ed Sheeran");
    assert(v[1].getArtist() == "Imagine Dragons");
    assert(v[2].getArtist() == "Linkin Park");

    srv.remove(v[0].getId());

    assert(srv.getAll().size() == 2);
}


void Tests::runAll()
{
    testDomain();
    testValidator();
    createTestFile();
    testRepo();
    createTestFile();
    testService();
    createTestFile();
    std::cout << "Toate testele au rulat cu succes!";
}
