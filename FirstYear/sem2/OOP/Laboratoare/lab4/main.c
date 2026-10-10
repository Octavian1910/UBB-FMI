#include "repository/repository.h"
#include "service/service.h"
#include "tests/teste.h"
#include "UI/ui.h"
#include <stddef.h>

int main()
{
    ruleazaToateTestele();

    RepoFarmacie repo = creeazaRepo();
    ServiceFarmacie service = creeaza_service_farmacie(&repo, NULL);
    UI ui = creeazaUI(&service);

    ruleazaUI(&ui);
    return 0;
}
