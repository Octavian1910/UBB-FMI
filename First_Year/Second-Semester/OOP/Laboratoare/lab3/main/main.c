
#include "../teste/teste.h"
#include "../ui/ui.h"
#include "../service/service.h"
#include "../repository/repository.h"

TEMA EX 7

int main() {
    teste_domain();
    teste_repository();
    teste_service();
    teste_ListedeListe();
    RepoCheltuieli* repo=creeaza_repo();
    ServiceCheltuieli* service=creeaza_service(repo);
    UI *ui=creeaza_ui(service);

    start(ui);
    distruge_ui(ui);

    return 0;

}