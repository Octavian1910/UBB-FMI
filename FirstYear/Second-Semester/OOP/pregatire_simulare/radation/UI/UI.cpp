//
// Created by octav on 21.05.2026.
//

#include "UI.h"

#include <iostream>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QListWidgetItem>
#include <QMessageBox>

UI::UI(Service& service) : service{service}
{
    auto* mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(radiationList);

    auto* addLayout = new QFormLayout;
    addLayout->addRow("ID", idEdit);
    addLayout->addRow("Description", descriptionEdit);
    addLayout->addRow("Frequency", frequencyEdit);
    addLayout->addRow("Type", typeEdit);

    mainLayout->addLayout(addLayout);
    mainLayout->addWidget(addButton);

    auto* filterLayout = new QHBoxLayout;

    frequencySlider->setMinimum(0);
    frequencySlider->setMaximum(100);
    frequencySlider->setValue(100);

    filterLayout->addWidget(new QLabel("Filter type"));
    filterLayout->addWidget(filterTypeEdit);
    filterLayout->addWidget(new QLabel("Max frequency"));
    filterLayout->addWidget(frequencySlider);
    filterLayout->addWidget(sliderValueLabel);

    mainLayout->addLayout(filterLayout);

    connect();

    populateList(this->service.get_all());
}

void UI::connect()
{
    QObject::connect(addButton, &QPushButton::clicked, [this]()
    {
        try
        {
            int id = idEdit->text().toInt();
            std::string description = descriptionEdit->text().toStdString();
            float frequency = frequencyEdit->text().toFloat();
            std::string type = typeEdit->text().toStdString();

            service.add(id, description, frequency, type);

            populateList(service.get_all());

            idEdit->clear();
            descriptionEdit->clear();
            frequencyEdit->clear();
            typeEdit->clear();
        }
        catch (std::exception& e)
        {
            QMessageBox::warning(this, "Error", e.what());
        }
    });

    QObject::connect(filterTypeEdit, &QLineEdit::textChanged, [this]()
    {
        filterList();
    });

    QObject::connect(frequencySlider, &QSlider::valueChanged, [this](int value)
    {
        sliderValueLabel->setText(QString::number(value));
        filterList();
    });
}

void UI::filterList()
{
    std::string type = filterTypeEdit->text().toStdString();
    float frequency = frequencySlider->value();

    populateList(service.filter_for_ui(frequency, type));
}

void UI::populateList(std::vector<Radiation> toDisplay)
{
    displayedRadiations = toDisplay;
    radiationList->clear();

    for (const Radiation& rad : displayedRadiations)
    {
        std::string displayText =
                std::to_string(rad.get_ID()) + " " +
                rad.get_description() + " " +
                std::to_string(rad.get_frequency()) + " " +
                rad.get_type_frequency();

        auto* item = new QListWidgetItem(QString::fromStdString(displayText));

        if (rad.get_type_frequency() == "alpha")
            item->setBackground(Qt::gray);
        else if (rad.get_type_frequency() == "beta")
            item->setBackground(Qt::green);
        else if (rad.get_type_frequency() == "gamma")
            item->setBackground(Qt::red);
        else if (rad.get_type_frequency() == "delta")
            item->setBackground(Qt::cyan);
        else if (rad.get_type_frequency() == "theta")
            item->setBackground(Qt::red);

        radiationList->addItem(item);
    }
}