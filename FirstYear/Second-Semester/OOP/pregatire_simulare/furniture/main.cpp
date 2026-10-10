#include <QApplication>

#include "Tests/Tests.h"
#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UI/UI.h"

int main(int argc, char *argv[])
{
    Tests::run_all();

    QApplication app(argc, argv);

    Repository repository("fisier.txt");
    Service service(repository);

    UI ui(service);
    ui.show();

    return app.exec();
}