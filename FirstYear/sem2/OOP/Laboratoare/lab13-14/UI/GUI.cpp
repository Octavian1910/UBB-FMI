#include "GUI.h"

#include "../repository/RepositoryException.h"
#include "../domain/validator/ValidatorException.h"
#include "../service/ServiceException.h"
#include "RecipeCRUDGUI.h"
#include "RecipeReadOnlyGUI.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>
#include <set>


GUI::GUI(MedService &serv):serv{serv}
{
    initGui();
    loadData(serv.getAll());
    reloadProducerButtons();
    initConnect();
}

void GUI::initGui()
{

    //main layout
    auto* mainLay = new QHBoxLayout;
    setLayout(mainLay);


    //left part , VERTICALA contine lista cu medicamente si un buton de search
    auto* medListLay = new QVBoxLayout;
    mainLay->addLayout(medListLay);

    //lista cu medicamente
    medList = new QListWidget;
    medListLay->addWidget(medList);

    //search
    txtSearch = new QLineEdit;
    medListLay->addWidget(txtSearch);

    //partea dreapta,cu toate functionalitatile
    auto* medButtonsLay = new QVBoxLayout;
    mainLay->addLayout(medButtonsLay);

    //formularul pt crud
    auto* formLay = new QFormLayout;
    txtName = new QLineEdit;
    txtPrice = new QLineEdit;
    txtProducer = new QLineEdit;
    txtSubstance = new QLineEdit;
    formLay->addRow("Name",txtName);
    formLay->addRow("Price",txtPrice);
    formLay->addRow("Producer",txtProducer);
    formLay->addRow("Substance",txtSubstance);

    medButtonsLay->addLayout(formLay);



    //crud buttons pe orizontala
    auto* crudLay = new QHBoxLayout;

    btnAdd = new QPushButton("Add");
    btnDelete = new QPushButton("Delete");
    btnUpdate = new QPushButton("Update");
    btnUndo = new QPushButton("Undo");
    btnOpenRecipeCRUD = new QPushButton("Open Recipe CRUD");
    btnOpenRecipeReadOnly = new QPushButton("Open Recipe ReadOnly");

    crudLay->addWidget(btnAdd);
    crudLay->addWidget(btnDelete);
    crudLay->addWidget(btnUpdate);
    crudLay->addWidget(btnUndo);

    medButtonsLay->addLayout(crudLay);

    //sort buttons pe orizontala

    auto* sortLay = new QHBoxLayout;

    btnSortName = new QPushButton("Sort Name");
    btnSortProducer = new QPushButton("Sort Producer");
    btnSortSubstance = new QPushButton("Sort Substance");

    radioAsc = new QRadioButton("Ascending");
    radioDesc = new QRadioButton("Descending");

    radioAsc->setChecked(true);

    sortLay->addWidget(btnSortName);
    sortLay->addWidget(btnSortProducer);
    sortLay->addWidget(btnSortSubstance);
    sortLay->addWidget(radioAsc);
    sortLay->addWidget(radioDesc);

    medButtonsLay->addLayout(sortLay);

    //filter buttons
    auto* filterLay = new QHBoxLayout;

    btnFilterPrice = new QPushButton("Filter Price");
    btnFilterSubstance = new QPushButton("Filter Substance");

    filterLay->addWidget(btnFilterPrice);
    filterLay->addWidget(btnFilterSubstance);

    medButtonsLay->addLayout(filterLay);


    //receipeButtons
    auto* receipeButtonsLay = new QVBoxLayout;
    mainLay->addLayout(receipeButtonsLay);

    btnAddReceipe = new QPushButton("Add receipe");
    btnClearReceipe = new QPushButton("Clear");
    btnGenerateReceipe = new QPushButton("Generate");
    btnExportReceipe = new QPushButton("Export");
    btnOpenRecipeCRUD = new QPushButton("Open Recipe CRUD");
    btnOpenRecipeReadOnly = new QPushButton("Open Recipe ReadOnly");

    receipeButtonsLay->addWidget(btnAddReceipe);
    receipeButtonsLay->addWidget(btnClearReceipe);
    receipeButtonsLay->addWidget(btnGenerateReceipe);
    receipeButtonsLay->addWidget(btnExportReceipe);
    receipeButtonsLay->addWidget(btnOpenRecipeCRUD);
    receipeButtonsLay->addWidget(btnOpenRecipeReadOnly);

    //lista cu receipe
    auto* receipeListLay = new QVBoxLayout;
    mainLay->addLayout(receipeListLay);

    recipeList = new QListWidget;
    receipeListLay->addWidget(recipeList);

    mainLay->addLayout(producerLay);

    resize(1420,500);
    setWindowTitle("Medicine GUI");



}

void GUI::loadData(const vector<Medicine> &meds)
{
    medList->clear();
    for (const auto& med : meds)
    {
        QString text = QString::fromStdString(med.get_name() + " | " + std::to_string(med.get_price()) + " | " + med.get_producer() + " | " + med.get_active_substance());
        medList->addItem(text);
    }
}

void GUI::loadData2(const vector<const Medicine *>& meds)
{
    medList->clear();
    for (const auto& med : meds)
    {
        QString text = QString::fromStdString(med->get_name() + " | " + std::to_string(med->get_price()) + " | " + med->get_producer() + " | " + med->get_active_substance());
        medList->addItem(text);
    }
}

void GUI::loadRecipe(const vector<const Medicine *> &meds)
{
    recipeList->clear();
    for (const auto& med : meds)
    {
        QString text = QString::fromStdString(med->get_name() + " | " + std::to_string(med->get_price()) + " | " + med->get_producer() + " | " + med->get_active_substance());
        recipeList->addItem(text);
    }
}

void GUI::reloadProducerButtons()
{
    auto meds = serv.getAll();

    std::map<string,int> producers;

    for (const auto& med : meds)
    {
        producers[med.get_producer()]++;
    }

    for (auto& pair : producerButtons) //eliberam memoria
    {
        producerLay->removeWidget(pair.second);
        delete pair.second;
    }

    producerButtons.clear(); //dam clear la map

    for (const auto& pair : producers)
    {
        string producer = pair.first;
        int count = pair.second;

        auto* btn =
            new QPushButton(
                QString::fromStdString(producer)
            );

        producerButtons[producer] = btn;

        producerLay->addWidget(btn);

        QObject::connect(
            btn,
            &QPushButton::clicked,
            [&,producer,count]()
            {
                QMessageBox::warning(this,"Producer info",QString::fromStdString(producer +" : " +std::to_string(count) +" medicamente"
                    )
                );
            });
    }
}


void GUI::initConnect()
{
    //add
    QObject::connect(btnAdd,&QPushButton::clicked,
    [&]()
        {
         string name = txtName->text().toStdString();
         int price = txtPrice->text().toInt();
         string producer = txtProducer->text().toStdString();
         string substance = txtSubstance->text().toStdString();

        try
        {
            serv.store(name,price,producer,substance);
            loadData(serv.getAll());
            reloadProducerButtons();
        }catch (RepositoryException& e)
        {
            QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
        }catch (ValidatorException& e)
        {
            QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
        }
        });

   //delete button
    QObject::connect(btnDelete,&QPushButton::clicked,
        [&]()
        {
           string name = txtName->text().toStdString();
           string producer = txtProducer->text().toStdString();
           string ID = name+"|"+producer;
           try
           {
               serv.remove(ID);
               loadData(serv.getAll());
               reloadProducerButtons();
           }catch (RepositoryException& e)
           {
               QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
           }
        });

    //update
    QObject::connect(btnUpdate,&QPushButton::clicked,
        [&]()
        {
           string name = txtName->text().toStdString();
           int price = txtPrice->text().toInt();
           string producer = txtProducer->text().toStdString();
           string substance = txtSubstance->text().toStdString();

            try
            {
                serv.update(name,price,producer,substance);
                loadData(serv.getAll());
            }catch (RepositoryException& e)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
            }
            catch (ValidatorException& e)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
            }

        });


    //undo
    QObject::connect(btnUndo,&QPushButton::clicked,
        [&]()
        {
           try
           {
               serv.undo();
               loadData(serv.getAll());
               reloadProducerButtons();
           }
            catch (ServiceException& e)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
            }
        });

    //search
    QObject::connect(
    txtSearch,
    &QLineEdit::returnPressed,
    [this]()
{
    string text =
        txtSearch->text().toStdString();



    if(text == "")
    {
        loadData(serv.getAll());

        return;
    }



    try
    {
        Medicine med =
            serv.find(text);

        medList->clear();

        QString item =
            QString::fromStdString(
                med.get_name() +
                " | " +
                std::to_string(med.get_price()) +
                " | " +
                med.get_producer() +
                " | " +
                med.get_active_substance()
            );

        medList->addItem(item);
    }

    catch(...)
    {
        medList->clear();
    }
});


    //sort Name
    QObject::connect(btnSortName,&QPushButton::clicked,
        [&]()
        {
            if (radioAsc->isChecked())
            {
                loadData2(serv.sortByName(true));
            }
            else loadData2(serv.sortByName(false));
        });


        //sort producer
        QObject::connect(btnSortProducer,&QPushButton::clicked,
            [&]()
            {
                if (radioAsc->isChecked())
                {
                    loadData2(serv.sortByProducer(true));
                }
                else loadData2(serv.sortByProducer(false));
            });

    //sort substance
    QObject::connect(btnSortSubstance,&QPushButton::clicked,
        [&]()
        {
           if (radioAsc->isChecked())
           {
               loadData2(serv.sortByActiveSubstance(true));
           }else loadData2(serv.sortByActiveSubstance(false));
        });

    //filter price
    QObject::connect(btnFilterPrice,&QPushButton::clicked,
        [&]()
        {
            int price = txtPrice->text().toInt();
            loadData2(serv.filterByPrice(price));
        });

    QObject::connect(btnFilterSubstance,&QPushButton::clicked,
        [&]()
        {
            string substance = txtSubstance->text().toStdString();
            loadData2(serv.filterBySubstance(substance));
        });


    //codurile pt receipe
    //add receipe
    QObject::connect(btnAddReceipe,&QPushButton::clicked,
        [&]()
        {
            try
            {
                string name = txtName->text().toStdString()+"|"+txtProducer->text().toStdString();
                serv.addToRecipe(name);
                loadRecipe(serv.getRecipe());
            }catch (RepositoryException& e)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
            }catch (ValidatorException& e)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
            }

        });

    QObject::connect(btnClearReceipe,&QPushButton::clicked,
        [&]()
        {
            serv.clearRecipe();
            loadRecipe(serv.getRecipe());
        });

    QObject::connect(btnGenerateReceipe,&QPushButton::clicked,
        [&]()
        {

            try
            {
                int number = txtPrice->text().toInt();
                serv.generateRecipe(number);
                loadRecipe(serv.getRecipe());
            }catch (ServiceException& e)
            {
                QMessageBox::warning(this,"Error",QString::fromStdString(e.getMessage()));
            }
        });

    QObject::connect(btnExportReceipe,&QPushButton::clicked,
        [&]()
        {
            serv.exportHTML("recipe.html");
            serv.exportCSV("recipe.csv");
        });


    QObject::connect(btnOpenRecipeCRUD, &QPushButton::clicked, [&]()
{
    auto* f = new RecipeCRUDGUI(serv);
    f->show();
});

    QObject::connect(btnOpenRecipeReadOnly, &QPushButton::clicked, [&]()
    {
        auto* f = new RecipeReadOnlyGUI(serv);
        f->show();
    });

}
