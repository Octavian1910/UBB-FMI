#include "../repository/PetRepo.h"
#include <assert.h>

#include "../service/PetStore.h"

void testRepo()
{
    PetRepo rep;
    Pet p{"A","A",10};
    rep.store(p);
    const vector<Pet>&  pets = rep.getAll();
    assert(pets.size() == 1);
    try
    {
        rep.store(p);
        assert(false);
    }
    catch (RepoException & e)
    {
        assert(true);
    }


    rep.store({"B","B",10});
    rep.store({"B","C",10});
    rep.store({"B","D",10});
    rep.store({"B","E",10});
    assert(pets.size() == 5);
}

void testService()
{
    void testAdd();
    PetRepo rep;
    PetStore serv{rep};
    serv.add("A","A",100);
    const auto& pets = serv.getAll();
    assert(pets.size() == 1);
}


void testAll()
{
    testRepo();
    testService();
    printf("Testele au rulat cu succes!\n");
}