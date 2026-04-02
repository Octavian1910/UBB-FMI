#include "tests/tests.h"
#include "UI/UI.h"


int main()
{
    testAll();
    MedRepository med{};
    MedValidator validator{};
    MedService service{med,validator};
    UI ui{service};
    ui.startUI();
    return 0;
}
