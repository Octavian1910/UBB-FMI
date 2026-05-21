


#include "Tests.h"
#include <QApplication>
#include <QPushButton>

#include "Repository/Repository.h"
#include "Service/Service.h"
#include "UI/UI.h"


int main(int argc,char* argv[])
{
    Tests::runAll();
    QApplication a(argc,argv);
    string file_path = "C:\\Users\\octav\\Desktop\\Facultate\\sem2\\OOP\\pregatire_examen_2\\repo.txt";
    Repository repo(file_path);
    Service serv{repo};
    UI ui(serv);
    ui.show();
    return QApplication::exec();
}
