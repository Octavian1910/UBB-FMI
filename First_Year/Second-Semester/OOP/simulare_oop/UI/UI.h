//
// Created by octav on 22.05.2026.
//

#ifndef SIMULARE_OOP_UI_H
#define SIMULARE_OOP_UI_H
#include <qobject.h>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <vector>

#include "../Domain/Postare.h"
#include "../Service/Service.h"
using std::vector;



class UI:public QWidget
{
    Q_OBJECT
private:
    Service& service;
    vector<Postare> displayed;
    QListWidget* lista_postari = new QListWidget;

    QLineEdit* cod_postare = new QLineEdit;
    QLineEdit* tip_continut = new QLineEdit;

    QPushButton* sort_by_creator_ascending = new QPushButton("Sorteaza dupa creator crescator");
    QPushButton* sort_by_creator_descending = new QPushButton("Sorteaza dupa creator descrescator");
    QPushButton* sort_by_platform_ascending = new QPushButton("Sorteaza dupa platforma crescator");
    QPushButton* sort_by_platform_descending = new QPushButton("Sorteaza dupa platforma descrescator");
    QPushButton* unsort = new QPushButton("Unsort");

    //da update la lista
    void load_data(vector<Postare> to_load);

    //conceteaza butoanele
    void connect_buttons();

    //returneaza indexul elementului selectat
    int get_index();
public:
    UI(Service& service);
};


#endif //SIMULARE_OOP_UI_H