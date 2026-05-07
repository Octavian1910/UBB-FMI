#include "tests/tests.h"
#include "repository/MedRepository.h"
#include "domain/validator/ValidatorMedicine.h"
#include "service/MedService.h"
#include "ui/UI.h"

int main()
{
    tests::testAll();

    MedRepository repo;
    ValidatorMedicine validator;

    MedService serv(repo, validator);

    UI ui(serv);

    ui.startUI();

    return 0;
}