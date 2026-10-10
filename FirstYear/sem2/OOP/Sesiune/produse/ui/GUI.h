//produse
#pragma once

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSlider>
#include <QLabel>
#include <QHeaderView>
#include <QMessageBox>
#include <QItemSelectionModel>
#include <QAbstractItemView>

#include <string>

#include "../service/Service.h"
#include "../repository/RepositoryException.h"
#include "../domain/validator/ValidatorException.h"
#include "PordusTableModel.h"

class GUI : public QWidget
{
private:
    Service& serv;

    QTableView* table;
    ProdusTableModel* model;

    QLineEdit* txtId;
    QLineEdit* txtNume;
    QLineEdit* txtTip;
    QLineEdit* txtPret;

    QPushButton* btnAdd;

    QSlider* slider;
    QLabel* lblSlider;

private:
    void initGUI()
    {
        auto* mainLay = new QVBoxLayout;
        setLayout(mainLay);

        table = new QTableView;
        model = new ProdusTableModel(serv);

        table->setModel(model);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        mainLay->addWidget(table);

        auto* formLay = new QFormLayout;

        txtId = new QLineEdit;
        txtNume = new QLineEdit;
        txtTip = new QLineEdit;
        txtPret = new QLineEdit;

        formLay->addRow("Id", txtId);
        formLay->addRow("Nume", txtNume);
        formLay->addRow("Tip", txtTip);
        formLay->addRow("Pret", txtPret);

        mainLay->addLayout(formLay);

        btnAdd = new QPushButton("Adauga");
        mainLay->addWidget(btnAdd);

        slider = new QSlider(Qt::Horizontal);
        slider->setMinimum(1);
        slider->setMaximum(100);
        slider->setValue(50);

        lblSlider = new QLabel("Pret <= 50");

        auto* sliderLay = new QHBoxLayout;
        sliderLay->addWidget(slider);
        sliderLay->addWidget(lblSlider);

        mainLay->addLayout(sliderLay);

        resize(900, 600);
        setWindowTitle("Produse");
    }

    void reloadAll()
    {
        model->refresh();
    }

    void connectSignals()
    {
        QObject::connect(slider, &QSlider::valueChanged, this, [&](int value)
        {
            lblSlider->setText("Pret <= " + QString::number(value));
            model->setPretMaxim(value);
        });

        QObject::connect(btnAdd, &QPushButton::clicked, this, [&]()
        {
            try
            {
                int id = txtId->text().toInt();
                std::string nume = txtNume->text().toStdString();
                std::string tip = txtTip->text().toStdString();
                double pret = txtPret->text().toDouble();

                serv.addProdus(id, nume, tip, pret);

                reloadAll();

                txtId->clear();
                txtNume->clear();
                txtTip->clear();
                txtPret->clear();
            }
            catch (ValidatorException& e)
            {
                QMessageBox::warning(this,
                                     "Validator",
                                     QString::fromStdString(e.getMessage()));
            }
            catch (RepositoryException& e)
            {
                QMessageBox::warning(this,
                                     "Repository",
                                     QString::fromStdString(e.getMessage()));
            }
        });
    }

public:

    GUI(Service& serv) : serv{serv}
    {
        initGUI();
        connectSignals();
        reloadAll();
    }
};