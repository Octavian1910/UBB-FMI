

#include "tests/Tests.h"
#include <QApplication>
#include <string>
#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UI/UI.h"
using std::string;


int main(int argc,char* argv[])
{
    Tests::run_all();

    QApplication app(argc,argv);

    string file = "postari.txt";

    Repository repo(file);
    Service serv{repo};
    UI ui{serv};
    ui.show();

    return QApplication::exec();

    return 0;
}