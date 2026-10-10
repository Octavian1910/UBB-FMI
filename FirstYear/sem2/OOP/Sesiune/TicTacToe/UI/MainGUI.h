//x si 0
#pragma once

#include <QWidget>
#include <QTableView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QHeaderView>
#include <QMessageBox>
#include <QAbstractItemView>

#include "../service/Service.h"
#include "../repository/RepositoryException.h"
#include "../domain/validator/ValidatorException.h"

#include "JocTableModel.h"

class MainGUI : public QWidget
{
private:
    Service& serv;

    JocTableModel* model;
    QTableView* table;

    QLineEdit* txtDim;
    QLineEdit* txtTabla;
    QLineEdit* txtJucator;
    QLineEdit* txtStare;

    QPushButton* btnAdd;
    QPushButton* btnUpdate;

    QTableWidget* boardTable;

    int selectedId = -1;

    void initGUI()
    {
        auto* lyMain = new QVBoxLayout;
        setLayout(lyMain);

        model = new JocTableModel(serv);

        table = new QTableView;
        table->setModel(model);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        lyMain->addWidget(table);

        auto* form = new QFormLayout;

        txtDim = new QLineEdit;
        txtTabla = new QLineEdit;
        txtJucator = new QLineEdit;
        txtStare = new QLineEdit;

        form->addRow("Dim", txtDim);
        form->addRow("Tabla", txtTabla);
        form->addRow("Jucator", txtJucator);
        form->addRow("Stare", txtStare);

        lyMain->addLayout(form);

        auto* btnLay = new QHBoxLayout;

        btnAdd = new QPushButton("Add");
        btnUpdate = new QPushButton("Update");

        btnLay->addWidget(btnAdd);
        btnLay->addWidget(btnUpdate);

        lyMain->addLayout(btnLay);

        boardTable = new QTableWidget;
        boardTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        boardTable->setSelectionMode(QAbstractItemView::NoSelection);
        boardTable->horizontalHeader()->setVisible(false);
        boardTable->verticalHeader()->setVisible(false);

        lyMain->addWidget(boardTable);

        resize(900, 700);
        setWindowTitle("Jocuri");
    }

    void clearBoard()
    {
        boardTable->clear();
        boardTable->setRowCount(0);
        boardTable->setColumnCount(0);
    }

    void loadBoard(const Joc& joc)
    {
        clearBoard();

        int dim = joc.getDim();
        string tabla = joc.getTabla();

        boardTable->setRowCount(dim);
        boardTable->setColumnCount(dim);

        for (int i = 0; i < dim; i++)
        {
            boardTable->setRowHeight(i, 50);

            for (int j = 0; j < dim; j++)
            {
                boardTable->setColumnWidth(j, 50);

                int poz = i * dim + j;

                QString txt = " ";

                if (tabla[poz] != '-')
                    txt = QString(QChar(tabla[poz]));

                auto* item = new QTableWidgetItem(txt);
                item->setTextAlignment(Qt::AlignCenter);

                boardTable->setItem(i, j, item);
            }
        }
    }

    void loadSelected()
    {
        auto sel = table->selectionModel()->selectedRows();

        if (sel.empty())
        {
            selectedId = -1;

            txtDim->clear();
            txtTabla->clear();
            txtJucator->clear();
            txtStare->clear();

            clearBoard();

            return;
        }

        int row = sel[0].row();

        auto jocuri = serv.getAllSorted();

        const auto& joc = jocuri[row];

        selectedId = joc.getId();

        txtDim->setText(QString::number(joc.getDim()));
        txtTabla->setText(QString::fromStdString(joc.getTabla()));
        txtJucator->setText(QString(QChar(joc.getJucatorCurent())));
        txtStare->setText(QString::fromStdString(joc.getStare()));

        loadBoard(joc);
    }

    void reload()
    {
        model->refresh();
        loadSelected();
    }

    void connectSignals()
    {
        QObject::connect(table->selectionModel(),
                         &QItemSelectionModel::selectionChanged,
                         [&](const QItemSelection&, const QItemSelection&)
        {
            loadSelected();
        });

        QObject::connect(btnAdd, &QPushButton::clicked, [&]()
        {
            try
            {
                int dim = txtDim->text().toInt();
                string tabla = txtTabla->text().toStdString();

                if (txtJucator->text().isEmpty())
                    throw ValidatorException("Jucator invalid!");

                char jucator = txtJucator->text()[0].toLatin1();

                int id = 1;

                for (const auto& joc : serv.getAll())
                    if (joc.getId() >= id)
                        id = joc.getId() + 1;

                serv.addJoc(id, dim, tabla, jucator, "Neinceput");

                reload();
            }
            catch (ValidatorException& e)
            {
                QMessageBox::warning(this, "Error", QString::fromStdString(e.getMessage()));
            }
            catch (RepositoryException& e)
            {
                QMessageBox::warning(this, "Error", QString::fromStdString(e.getMessage()));
            }
        });

        QObject::connect(btnUpdate, &QPushButton::clicked, [&]()
        {
            if (selectedId == -1)
                return;

            try
            {
                int dim = txtDim->text().toInt();
                string tabla = txtTabla->text().toStdString();

                if (txtJucator->text().isEmpty())
                    throw ValidatorException("Jucator invalid!");

                char jucator = txtJucator->text()[0].toLatin1();

                string stare = txtStare->text().toStdString();

                serv.updateJoc(selectedId, dim, tabla, jucator, stare);

                reload();
            }
            catch (ValidatorException& e)
            {
                QMessageBox::warning(this, "Error", QString::fromStdString(e.getMessage()));
            }
            catch (RepositoryException& e)
            {
                QMessageBox::warning(this, "Error", QString::fromStdString(e.getMessage()));
            }
        });
    }

public:
    MainGUI(Service& serv) : serv(serv)
    {
        initGUI();
        connectSignals();
        model->refresh();
    }
};