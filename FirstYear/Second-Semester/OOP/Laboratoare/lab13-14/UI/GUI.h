#pragma once
#include "../Service/MedService.h"
#include "RecipeCRUDGUI.h"
#include "RecipeReadOnlyGUI.h"

#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <map>

class QVBoxLayout;

class GUI : public QWidget
{
private:
    /*
     * serv: service reference
     */
    MedService& serv;

    /*
     * medList: medicine list widget
     * recipeList: recipe list widget
     */
    QListWidget* medList;
    QListWidget* recipeList;

    /*
     * txtName: textbox for medicine name
     * txtPrice: textbox for medicine price
     * txtProducer: textbox for producer
     * txtSubstance: textbox for active substance
     * txtSearch: textbox for searching
     */
    QLineEdit* txtName;
    QLineEdit* txtPrice;
    QLineEdit* txtProducer;
    QLineEdit* txtSubstance;
    QLineEdit* txtSearch;

    /*
     * CRUD buttons
     */
    QPushButton* btnAdd;
    QPushButton* btnDelete;
    QPushButton* btnUpdate;
    QPushButton* btnUndo;
    QPushButton* btnOpenRecipeCRUD;
    QPushButton* btnOpenRecipeReadOnly;

    /*
     * Sort buttons
     */
    QPushButton* btnSortName;
    QPushButton* btnSortProducer;
    QPushButton* btnSortSubstance;

    /*
     * Recipe buttons
     */
    QPushButton* btnAddReceipe;
    QPushButton* btnClearReceipe;
    QPushButton* btnGenerateReceipe;
    QPushButton* btnExportReceipe;

    /*
     * radioAsc: ascending sort
     * radioDesc: descending sort
     */
    QRadioButton* radioAsc;
    QRadioButton* radioDesc;

    /*
     * Filter buttons
     */
    QPushButton* btnFilterPrice;
    QPushButton* btnFilterSubstance;

    /*
     * Initializes GUI components
     */
    void initGui();

    /*
     * Loads medicines into list
     * :param meds: medicine vector
     */
    void loadData(const vector<Medicine>& meds);

    /*
     * Loads filtered/sorted medicines
     * :param meds: medicine vector
     */
    void loadData2(const vector<const Medicine*>& meds);

    /*
     * Loads recipe medicines
     * :param meds: recipe vector
     */
    void loadRecipe(const vector<const Medicine*>& meds);

    /*
     * Initializes signals and slots
     */
    void initConnect();
    void reloadProducerButtons();

    QVBoxLayout* producerLay = new QVBoxLayout; //layerul cu butoane
    std::map<string,QPushButton*> producerButtons; //tine minte butoanele


public:
    /*
     * Creates GUI
     * :param serv: service reference
     */
    GUI(MedService& serv);
};
