#include "repository/PetRepo.h"
#include "service/PetStore.h"
#include "UI/UI.h"
#include "tests/test.h"

int main()
{
    testAll();

    PetRepo rep;
    PetStore serv{rep};
    UI ui{serv};
    ui.startUI();
    return 0;
}