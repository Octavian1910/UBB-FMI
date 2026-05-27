#pragma once

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QMessageBox>

#include "../service/MedService.h"
#include "../service/Observer.h"
#include "../service/ServiceException.h"
#include "RecipeTableModel.h"

class RecipeCRUDGUI : public QWidget, public Observer
{
private:
    /*
     * serv: service reference
     */
    MedService& serv;

    /*
     * table: table view for recipe medicines
     */
    QTableView* table;

    /*
     * btnClear: button for clearing recipe
     * btnGenerate: button for generating recipe
     */
    QPushButton* btnClear;
    QPushButton* btnGenerate;

    /*
     * txtNumber: textbox for number of generated medicines
     */
    QLineEdit* txtNumber;

    /*
     * model: table model for recipe medicines
     */
    RecipeTableModel* model;

    /*
     * Initializes GUI components
     */
    void initGUI()
    {
        auto* mainLay = new QVBoxLayout;
        setLayout(mainLay);

        table = new QTableView;
        model = new RecipeTableModel(serv.getRecipe());
        table->setModel(model);

        mainLay->addWidget(table);

        auto* formLay = new QFormLayout;
        txtNumber = new QLineEdit;
        formLay->addRow("Number", txtNumber);
        mainLay->addLayout(formLay);

        btnClear = new QPushButton("Clear recipe");
        btnGenerate = new QPushButton("Generate recipe");

        mainLay->addWidget(btnClear);
        mainLay->addWidget(btnGenerate);

        setWindowTitle("Recipe CRUD");
        resize(600, 400);
    }

    /*
     * Connects signals and slots
     */
    void connectSignals()
    {
        QObject::connect(btnClear, &QPushButton::clicked,
            [&]()
            {
                serv.clearRecipe();
            });

        QObject::connect(btnGenerate, &QPushButton::clicked,
            [&]()
            {
                try
                {
                    int n = txtNumber->text().toInt();
                    serv.generateRecipe(n);
                }
                catch (ServiceException& e)
                {
                    QMessageBox::warning(this, "Error", QString::fromStdString(e.getMessage()));
                }
            });
    }

public:
    /*
     * Creates recipe CRUD GUI
     * :param serv: service reference
     */
    RecipeCRUDGUI(MedService& serv) : serv(serv)
    {
        initGUI();
        connectSignals();

        serv.addObserver(this);
        update();
    }

    /*
     * Updates table data when recipe changes
     */
    void update() override
    {
        model->setMeds(serv.getRecipe());
    }

    /*
     * Destructor
     */
    ~RecipeCRUDGUI()
    {
        serv.removeObserver(this);
    }
};