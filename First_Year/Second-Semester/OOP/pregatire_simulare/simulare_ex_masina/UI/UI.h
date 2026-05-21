//
// Created by octav on 21.05.2026.
//

#ifndef SIMULARE_EX_MASINA_UI_H
#define SIMULARE_EX_MASINA_UI_H
#include <QApplication>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <qcoreapplication.h>
#include "../Service/Service.h"
#include "../domain/Car.h"

class UI : public QWidget
{
    Q_OBJECT;

private:
    Service& serv;
    std::vector<Car> displayed_cars;

    QTableWidget* cars_table = new QTableWidget;
    QLineEdit* filter_input = new QLineEdit;

    QPushButton* filter_button = new QPushButton("Filter");
    QPushButton* sort_ascending_button = new QPushButton("Sort ascending");
    QPushButton* sort_descending_button = new QPushButton("Sort descending");
    QPushButton* reset_button = new QPushButton("Reset");

public:
    UI(Service& service);

    void connect_buttons();
    void load_data(std::vector<Car> to_display);
    int get_selected_index();
};


#endif //SIMULARE_EX_MASINA_UI_H