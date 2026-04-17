#include "tests/tests.h"
#include "../domain/validator/MedValidator.h"
#include "../repository/MedRepository.h"
#include "../service/MedService.h"
#include "../UI/UI.h"


int main() {
    TestMedService tests;
    tests.runAll();
    MedRepository repo;
    MedValidator val;
    MedService serv{ repo, val };
    UI ui{ serv };

    ui.startUI();

    return 0;
}