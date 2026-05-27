#ifndef FURNITURE_UI_H
#define FURNITURE_UI_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QLabel>

#include "../Service/Service.h"

class UI : public QWidget
{
private:
    Service& service;

    QTableWidget* table = new QTableWidget;

    QLineEdit* idEdit = new QLineEdit;
    QLineEdit* typeEdit = new QLineEdit;
    QLineEdit* piecesEdit = new QLineEdit;
    QLineEdit* timeEdit = new QLineEdit;

    QPushButton* addButton = new QPushButton("Add");

    QCheckBox* nightstandCheck = new QCheckBox("nightstand");
    QCheckBox* bedCheck = new QCheckBox("bed");
    QCheckBox* tableCheck = new QCheckBox("table");
    QCheckBox* wardrobeCheck = new QCheckBox("wardrobe");

    QRadioButton* sortPiecesRadio = new QRadioButton("Numar piese");
    QRadioButton* sortTimeRadio = new QRadioButton("Timp asamblare");

    void connect_buttons();
    void load_data(std::vector<Furniture> data);
    void reload_filtered_sorted();

public:
    UI(Service& service);
};

#endif