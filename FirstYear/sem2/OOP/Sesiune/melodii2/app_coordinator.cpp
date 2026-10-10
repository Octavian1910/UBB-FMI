#include <QApplication>

#include "tests/Tests.h"
#include "repository/Repo.h"
#include "service/Service.h"
#include "validator/Validator.h"
#include "ui/GUI.h"

int main(int argc, char *argv[])
{
    Tests::runAll();

    QApplication app(argc, argv);

    Validator val;
    Repo repo("melodii.txt");
    Service srv(repo, val);

    GUI gui(srv);
    gui.show();

    return app.exec();

    return 0;
}