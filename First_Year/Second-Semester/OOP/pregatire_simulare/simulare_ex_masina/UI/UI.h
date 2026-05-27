//
// Created by octav on 21.05.2026.
//

#ifndef SIMULARE_EX_MASINA_UI_H
#define SIMULARE_EX_MASINA_UI_H
#include <QWidget>
#include <vector>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QObject>
#include <QTableWidget>
#include <QVBoxLayout>
#include "../Service/Service.h"
using std::vector;
class UI:public QWidget
{
    Q_OBJECT;
private:
    Service& service;
    vector<Car> displayed_cars;

    QTableWidget* cars_table = new QTableWidget;
    QLineEdit* filter_input = new QLineEdit;

    QPushButton* filter_button = new QPushButton("Filter");
    QPushButton* sort_by_price_ascending_button = new QPushButton("Price ascending");
    QPushButton* sort_by_price_descending_button = new QPushButton("Price descending");
    QPushButton* reset_button = new QPushButton("Reset");

public:
    UI(Service& service);
    void load_data(vector<Car> items_to_load);
    int get_selected_index();
    void connect_buttons();
};


#endif //SIMULARE_EX_MASINA_UI_H