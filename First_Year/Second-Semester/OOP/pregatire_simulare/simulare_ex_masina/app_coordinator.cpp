#include <QApplication>

#include "tests/Tests.h"
#include <string>

#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UI/UI.h"
using std::string;

int main(int argc,char* argv[])
{
	Tests::runAll();

    QApplication app(argc,argv);

    std::string file_path = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\simulare_ex_masina\\cars.txt";

    Repository repo(file_path);
    Service serv{repo};
    UI ui{serv};
    ui.show();

    return QApplication::exec();

    return 0;
}