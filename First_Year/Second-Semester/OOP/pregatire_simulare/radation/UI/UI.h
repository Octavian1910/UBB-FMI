//
// Created by octav on 21.05.2026.
//

#ifndef RADATION_UI_H
#define RADATION_UI_H

#include "../Service/Service.h"

#include <vector>
#include <string>

#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

class UI : public QWidget
{
    Q_OBJECT

private:
    Service& service;
    std::vector<Radiation> displayedRadiations;

    QListWidget* radiationList = new QListWidget;

    QLineEdit* idEdit = new QLineEdit;
    QLineEdit* descriptionEdit = new QLineEdit;
    QLineEdit* frequencyEdit = new QLineEdit;
    QLineEdit* typeEdit = new QLineEdit;

    QPushButton* addButton = new QPushButton("Add radiation");

    QLineEdit* filterTypeEdit = new QLineEdit;
    QSlider* frequencySlider = new QSlider(Qt::Horizontal);
    QLabel* sliderValueLabel = new QLabel("100");

public:
    UI(Service& service);

    void connect();
    void filterList();
    void populateList(std::vector<Radiation> toDisplay);
};

#endif // RADATION_UI_H