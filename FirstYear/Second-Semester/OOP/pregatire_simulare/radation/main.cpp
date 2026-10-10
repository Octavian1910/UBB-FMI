#include <QApplication>
#include <QPushButton>

#include "tests/Tests.h"
#include "Service/Service.h"
#include "Repository/Repository.h"
#include "UI/UI.h"

int main(int argc, char *argv[])
{
    Tests::test_all();

    QApplication a(argc, argv);

    Repository repository("test_frecventa.txt");
    Service service(repository);

    UI ui(service);
    ui.show();

    return QApplication::exec();
}