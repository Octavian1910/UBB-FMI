#include "UI.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <algorithm>

UI::UI(Service& service) : service(service)
{
    auto* mainLayout = new QVBoxLayout(this);

    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"ID", "Type", "Nr pieces", "Assembly time"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    mainLayout->addWidget(table);

    auto* formLayout = new QFormLayout;
    formLayout->addRow("ID", idEdit);
    formLayout->addRow("Type", typeEdit);
    formLayout->addRow("Nr pieces", piecesEdit);
    formLayout->addRow("Assembly time", timeEdit);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(addButton);

    auto* checkLayout = new QHBoxLayout;
    checkLayout->addWidget(nightstandCheck);
    checkLayout->addWidget(bedCheck);
    checkLayout->addWidget(tableCheck);
    checkLayout->addWidget(wardrobeCheck);

    mainLayout->addLayout(checkLayout);

    auto* radioLayout = new QHBoxLayout;
    radioLayout->addWidget(sortPiecesRadio);
    radioLayout->addWidget(sortTimeRadio);

    mainLayout->addLayout(radioLayout);

    connect_buttons();
    load_data(service.get_all());
}

void UI::connect_buttons()
{
    QObject::connect(addButton, &QPushButton::clicked, [this]()
    {
        try
        {
            int id = idEdit->text().toInt();
            std::string type = typeEdit->text().toStdString();
            int nr_pieces = piecesEdit->text().toInt();
            int time = timeEdit->text().toInt();

            service.add(id, type, nr_pieces, time);

            idEdit->clear();
            typeEdit->clear();
            piecesEdit->clear();
            timeEdit->clear();

            reload_filtered_sorted();
        }
        catch (std::exception& e)
        {
            QMessageBox::warning(this, "Error", e.what());
        }
    });

    QObject::connect(nightstandCheck, &QCheckBox::checkStateChanged, [this]()
    {
        reload_filtered_sorted();
    });

    QObject::connect(bedCheck, &QCheckBox::checkStateChanged, [this]()
    {
        reload_filtered_sorted();
    });

    QObject::connect(tableCheck, &QCheckBox::checkStateChanged, [this]()
    {
        reload_filtered_sorted();
    });

    QObject::connect(wardrobeCheck, &QCheckBox::checkStateChanged, [this]()
    {
        reload_filtered_sorted();
    });

    QObject::connect(sortPiecesRadio, &QRadioButton::clicked, [this]()
    {
        reload_filtered_sorted();
    });

    QObject::connect(sortTimeRadio, &QRadioButton::clicked, [this]()
    {
        reload_filtered_sorted();
    });
}

void UI::reload_filtered_sorted()
{
    std::vector<bool> checked = {
        nightstandCheck->isChecked(),
        bedCheck->isChecked(),
        tableCheck->isChecked(),
        wardrobeCheck->isChecked()
    };

    std::vector<Furniture> data = service.filter_by_types(checked);

    if (sortPiecesRadio->isChecked())
    {
        std::sort(data.begin(), data.end(), [](const Furniture& a, const Furniture& b)
        {
            return a.get_nr_pieces() < b.get_nr_pieces();
        });
    }

    if (sortTimeRadio->isChecked())
    {
        std::sort(data.begin(), data.end(), [](const Furniture& a, const Furniture& b)
        {
            return a.get_time() < b.get_time();
        });
    }

    load_data(data);
}

void UI::load_data(std::vector<Furniture> data)
{
    table->clearContents();
    table->setRowCount(data.size());

    int row = 0;

    for (const auto& f : data)
    {
        table->setItem(row, 0, new QTableWidgetItem(QString::number(f.get_id())));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(f.get_type())));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(f.get_nr_pieces())));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(f.get_time())));

        row++;
    }
}