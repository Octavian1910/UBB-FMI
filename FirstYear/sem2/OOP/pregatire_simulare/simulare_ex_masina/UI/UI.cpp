//
// Created by octav on 21.05.2026.
//

#include "UI.h"


UI::UI(Service &service):service(service)
{
    cars_table->setColumnCount(3);
    cars_table->setHorizontalHeaderLabels({"Nume", "Specie", "Varsta"});

    QVBoxLayout* mainLay = new QVBoxLayout(this);
    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    mainLay->addWidget(cars_table);
    mainLay->addWidget(filter_input);
    mainLay->addLayout(buttonsLayout);

    buttonsLayout->addWidget(sort_by_price_ascending_button);
    buttonsLayout->addWidget(sort_by_price_descending_button);
    buttonsLayout->addWidget(reset_button);
    buttonsLayout->addWidget(filter_button);

    connect_buttons();
    load_data(service.get_all());
}

int UI::get_selected_index()
{
    int index = cars_table->currentRow();
    if (index < 0)
        return -1;

    return index;
}


void UI::connect_buttons()
{
    QObject::connect(filter_button,&QPushButton::clicked,
        [this]()
        {
            string brand = filter_input->text().toStdString();
           load_data(service.filter_by_brand(brand));
        });

    QObject::connect(sort_by_price_ascending_button,&QPushButton::clicked,
        [this]()
        {
           load_data(service.sort_by_age(true));
        });

    QObject::connect(sort_by_price_descending_button,&QPushButton::clicked,
        [this]()
        {
           load_data(service.sort_by_age(false));
        });

    QObject::connect(reset_button,&QPushButton::clicked,
        [this]()
        {
           load_data(service.get_all());
        });

    QObject::connect(cars_table,&QTableWidget::itemSelectionChanged,
        [this]()
        {
           int index = get_selected_index();

            if (index == -1)
                return;

            if (displayed_cars[index].get_age() >= 10)
            {
                QMessageBox::warning(this,"Info","etc");
            }
        });

}


void UI::load_data(vector<Car> items_to_load)
{
    displayed_cars = items_to_load;

    cars_table->clearContents();
    cars_table->setRowCount(displayed_cars.size());

    for (int i = 0 ; i < displayed_cars.size() ; ++i)
    {
        Car car = displayed_cars.at(i);

        auto* name_item = new QTableWidgetItem(QString::fromStdString(car.get_model()));
        auto* specie_item = new QTableWidgetItem(QString::fromStdString(car.get_brand()));
        auto* age_item = new QTableWidgetItem(QString::number(car.get_age()));

        if (car.get_brand() == "sedan")
            name_item->setBackground(Qt::red);

        if (car.get_brand() == "SUV")
            name_item->setBackground(Qt::gray);

        if (car.get_brand() == "cabriolet")
            name_item->setBackground(Qt::green);

        if (car.get_brand() == "camioneta")
            name_item->setBackground(Qt::white);


        cars_table->setItem(i,0,name_item);
        cars_table->setItem(i,1,specie_item);
        cars_table->setItem(i,2,age_item);
    }
}
