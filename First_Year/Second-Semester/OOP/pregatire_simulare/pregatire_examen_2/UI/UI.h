//
// Created by octav on 21.05.2026.
//

#ifndef PREGATIRE_EXAMEN_2_UI_H
#define PREGATIRE_EXAMEN_2_UI_H
#include <qwidget.h>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QMessageBox>
#include <iostream>
#include "../Service/Service.h"

class UI : public QWidget
{
    Q_OBJECT
private:
    Service& service;
    vector<Skirt> displayed_skirts;

    QListWidget* skirts_list;
    QPushButton* rent_button;
    QPushButton* sort_by_price_button;
    QPushButton* sort_by_size_button;
    QPushButton* unsorted_button;

    void connect_buttons();
    int get_selected_index();
    void load_list(vector<Skirt> to_display);
public:
    UI(Service& service);
};
#endif //PREGATIRE_EXAMEN_2_UI_H