//melodii2 mytablemodel
#pragma once

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include "../service/Service.h"
#include "MyTableModel.h"

class GUI : public QWidget
{
private:
    Service& srv;

    MyTableModel* model;
    QTableView* table=new QTableView;

    QLineEdit* txtTitlu=new QLineEdit;
    QLineEdit* txtArtist=new QLineEdit;
    QLineEdit* txtGen=new QLineEdit;

    QPushButton* btnAdd=new QPushButton("Add");
    QPushButton* btnDelete=new QPushButton("Delete");

    void initGUI()
    {
        auto* mainLy=new QHBoxLayout;
        setLayout(mainLy);

        model=new MyTableModel(srv);
        table->setModel(model);

        mainLy->addWidget(table);

        auto* rightLy=new QVBoxLayout;

        auto* form=new QFormLayout;
        form->addRow("Titlu",txtTitlu);
        form->addRow("Artist",txtArtist);
        form->addRow("Gen",txtGen);

        rightLy->addLayout(form);

        rightLy->addWidget(btnAdd);
        rightLy->addWidget(btnDelete);

        mainLy->addLayout(rightLy);
    }

    void connectSignals()
    {
        QObject::connect(btnAdd,&QPushButton::clicked,[&]()
        {
            try
            {
                srv.add(txtTitlu->text().toStdString(),
                        txtArtist->text().toStdString(),
                        txtGen->text().toStdString());

                model->refresh();

                txtTitlu->clear();
                txtArtist->clear();
                txtGen->clear();
            }
            catch(const ValidatorException& ex)
            {
                QMessageBox::warning(this,"Eroare",
                    QString::fromStdString(ex.getMessage()));
            }
            catch(const RepoException& ex)
            {
                QMessageBox::warning(this,"Eroare",
                    QString::fromStdString(ex.getMessage()));
            }
        });

        QObject::connect(btnDelete,&QPushButton::clicked,[&]()
        {
            auto index=table->currentIndex();

            if(!index.isValid())
                return;

            Melodie m=model->getMelodie(index.row());

            try
            {
                srv.remove(m.getId());

                model->refresh();
            }
            catch(const RepoException& ex)
            {
                QMessageBox::warning(this,"Eroare",
                    QString::fromStdString(ex.getMessage()));
            }
        });
    }

public:
    GUI(Service& srv):srv{srv}
    {
        initGUI();
        connectSignals();
    }
};