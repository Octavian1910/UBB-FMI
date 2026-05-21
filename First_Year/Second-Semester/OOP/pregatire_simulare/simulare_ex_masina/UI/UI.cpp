//
// Created by octav on 21.05.2026.
//

#include "UI.h"

UI::UI(Service &service): serv{service}
{
  auto* main_layout = new QVBoxLayout(this);
  auto* buttons_layout = new QHBoxLayout;

    cars_table->setColumnCount(3);
    cars_table->setHorizontalHeaderLabels({"Nume","Specie","Varsta"});

    filter_input->setPlaceholderText("Specie");

    main_layout->addWidget(cars_table);
    main_layout->addWidget(filter_input);
    main_layout->addLayout(buttons_layout);

    buttons_layout->addWidget(filter_button);
    buttons_layout->addWidget(sort_ascending_button);
    buttons_layout->addWidget(sort_descending_button);
    buttons_layout->addWidget(reset_button);

    connect_buttons();
    load_data(serv.get_all());
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
            load_data(serv.filter_by_brand(brand));
        });

    QObject::connect(sort_ascending_button,&QPushButton::clicked,
        [this]()
        {
            auto result = serv.sort_by_age(true);
            load_data(result);
        });

    QObject::connect(sort_descending_button,&QPushButton::clicked,
        [this]()
        {
            auto result = serv.sort_by_age(false);
            load_data(result);
        });

    QObject::connect(cars_table,&QTableWidget::itemSelectionChanged,
        [this]()
        {
           int index = get_selected_index();

            if (index == -1)
                return;

            if (displayed_cars[index].get_age() >= 10)
               QMessageBox::warning(this,"Info","Masina este in varsta si necesita un control!");
        });


    QObject::connect(reset_button, &QPushButton::clicked,
    [this]()
    {
        filter_input->clear();
        load_data(serv.get_all());
    });
}


void UI::load_data(std::vector<Car> to_display)
{
    displayed_cars = to_display;

    cars_table->clearContents();
    cars_table->setRowCount(displayed_cars.size());

    for (int i = 0; i < displayed_cars.size(); i++)
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

        cars_table->setItem(i, 0, name_item);
        cars_table->setItem(i, 1, specie_item);
        cars_table->setItem(i, 2, age_item);
    }
}