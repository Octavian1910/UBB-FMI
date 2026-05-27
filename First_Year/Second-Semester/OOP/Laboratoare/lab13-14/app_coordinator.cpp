#include "tests/tests.h"
#include "repository/MedRepository.h"
#include "domain/validator/ValidatorMedicine.h"
#include "service/MedService.h"
#include "ui/GUI.h"
#include <QApplication>
int main(int argc,char * argv[])
{
    QApplication app(argc, argv);
    tests::testAll();

    MedRepository repo;
    ValidatorMedicine validator;

    MedService serv(repo, validator);

    GUI gui(serv);
    gui.show();

    return app.exec();
}
