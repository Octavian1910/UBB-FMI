#include <stdlib.h>
#include "repository/repository.h"
#include "service/service.h"
#include "tests/teste.h"
#include "UI/ui.h"




int main()
{
    ruleazaToateTestele();
    RepoFarmacie* repo = creeazaRepo();
    ValidatorMedicament* validator = NULL;
    ServiceFarmacie *service = creeaza_service_farmacie(repo,validator);
    UI* ui = creeazaUI(service);
    ruleazaUI(ui);
    return 0;
}
