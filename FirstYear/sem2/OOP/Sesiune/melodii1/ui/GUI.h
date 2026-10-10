//melodii1
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
#include <QMessageBox>
#include <QHeaderView>

#include "../service/MelodieService.h"
#include "../repository/RepositoryException.h"
#include "../domain/validator/ValidatorException.h"
#include "../service/ServiceException.h"

#include "MelodieTableModel.h"

class GUI : public QWidget
{
private:
    MelodieService& serv;

    QTableView* table;
    MelodieTableModel* model;

    QLineEdit* txtTitle;
    QSlider* sliderRank;
    QLabel* lblRank;

    QPushButton* btnUpdate;
    QPushButton* btnDelete;

    int selectedId=-1;

    void initGUI()
    {
        auto* lyMain=new QVBoxLayout;
        setLayout(lyMain);

        table=new QTableView;
        model=new MelodieTableModel(serv);

        table->setModel(model);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        lyMain->addWidget(table);

        auto* form=new QFormLayout;

        txtTitle=new QLineEdit;
        form->addRow("Title",txtTitle);

        sliderRank=new QSlider(Qt::Horizontal);
        sliderRank->setMinimum(0);
        sliderRank->setMaximum(10);

        lblRank=new QLabel("0");

        auto* rankLay=new QHBoxLayout;
        rankLay->addWidget(sliderRank);
        rankLay->addWidget(lblRank);

        form->addRow("Rank",rankLay);

        lyMain->addLayout(form);

        auto* btnLay=new QHBoxLayout;

        btnUpdate=new QPushButton("Update");
        btnDelete=new QPushButton("Delete");

        btnLay->addWidget(btnUpdate);
        btnLay->addWidget(btnDelete);

        lyMain->addLayout(btnLay);

        resize(800,600);
    }

    void reload()
    {
        model->refresh();
    }

    void loadSelected()
    {
        auto selected=table->selectionModel()->selectedRows();

        if(selected.empty())
        {
            selectedId=-1;
            txtTitle->clear();
            sliderRank->setValue(0);
            lblRank->setText("0");
            return;
        }

        int row=selected[0].row();

        Melodie m=model->getMelodie(row);

        selectedId=m.get_ID();

        txtTitle->setText(QString::fromStdString(m.get_title()));
        sliderRank->setValue(m.get_rank());
        lblRank->setText(QString::number(m.get_rank()));
    }

    void connectSignals()
    {
        QObject::connect(sliderRank,&QSlider::valueChanged,[&](int value)
        {
            lblRank->setText(QString::number(value));
        });

        QObject::connect(table->selectionModel(),&QItemSelectionModel::selectionChanged,[&](const QItemSelection&,const QItemSelection&)
        {
            loadSelected();
        });

        QObject::connect(btnUpdate,&QPushButton::clicked,[&]()
        {
            if(selectedId==-1)
            {
                QMessageBox::warning(this,"Error","No song selected!");
                return;
            }

            try
            {
                serv.update(selectedId,txtTitle->text().toStdString(),sliderRank->value());
                reload();
                loadSelected();
            }
            catch(ValidatorException& ex)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(ex.getMessage()));
            }
            catch(RepositoryException& ex)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(ex.getMessage()));
            }
        });

        QObject::connect(btnDelete,&QPushButton::clicked,[&]()
        {
            if(selectedId==-1)
            {
                QMessageBox::warning(this,"Error","No song selected!");
                return;
            }

            try
            {
                serv.remove(selectedId);

                selectedId=-1;

                txtTitle->clear();
                sliderRank->setValue(0);
                lblRank->setText("0");

                reload();
            }
            catch(ServiceException& ex)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(ex.getMessage()));
            }
            catch(RepositoryException& ex)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(ex.getMessage()));
            }
        });
    }

public:
    GUI(MelodieService& serv):serv(serv)
    {
        initGUI();
        connectSignals();
        reload();
    }
};