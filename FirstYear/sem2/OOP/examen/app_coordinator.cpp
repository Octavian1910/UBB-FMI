#include <QApplication>

#include "tests/tests.h"
#include "ui/GUI.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    tests::runAll();

    MelodieRepository repo{"melodii.txt"};
    ValidatorMelodie validator;
    MelodieService serv{repo, validator};

    GUI gui{serv};
    gui.show();

    return app.exec();
}
