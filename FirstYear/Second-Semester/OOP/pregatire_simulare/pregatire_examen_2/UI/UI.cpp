//
// Created by octav on 21.05.2026.
//

#include "UI.h"


UI::UI(Service &service):service{service}
{
    skirts_list = new QListWidget;
    rent_button = new QPushButton("Rent");
    sort_by_price_button = new QPushButton("Sort by price");
    sort_by_size_button = new QPushButton("Sort by size");
    unsorted_button = new QPushButton("Unsort");

    auto* main_layout = new QHBoxLayout;
    this->setLayout(main_layout);
    auto* buttons_layout = new QVBoxLayout;

    buttons_layout->addWidget(rent_button);
    buttons_layout->addWidget(sort_by_price_button);
    buttons_layout->addWidget(sort_by_size_button);
    buttons_layout->addWidget(unsorted_button);

    main_layout->addWidget(skirts_list);
    main_layout->addLayout(buttons_layout);

    connect_buttons();
    load_list(service.get_all());
}

void UI::connect_buttons()
{
    QObject::connect(skirts_list,&QListWidget::itemSelectionChanged,
        [this]()
        {
           int index = get_selected_index();
           std::cout << index;
        });

    QObject::connect(rent_button,&QPushButton::clicked,
        [this]()
        {
          int index = get_selected_index();

            if (index == -1)
                return;

            try
            {
                Skirt element = displayed_skirts.at(index);
                service.rentSkirt(element.get_ID());
                load_list(service.get_all());
            }
            catch (std::runtime_error& e)
            {
                QMessageBox::warning(this,"Could not rent","Skirt unavailable");
            }
        });

    QObject::connect(sort_by_price_button,&QPushButton::clicked,
        [this]()
        {
           load_list(service.sortSkirtsByPrice());
        });


    QObject::connect(sort_by_size_button,&QPushButton::clicked,
        [this]()
        {
           load_list(service.sortSkirtsBySize());
        });

    QObject::connect(unsorted_button,&QPushButton::clicked,
        [this]()
        {
           load_list(service.get_all());
        });
}

int UI::get_selected_index()
{
    auto index = skirts_list->selectionModel() -> selectedRows();

    if (index.empty())
        return  -1;

    return index.at(0).row();
}

void UI::load_list(vector<Skirt> to_display)
{
    displayed_skirts = to_display;
    skirts_list->clear();
    for (const Skirt& skirt : displayed_skirts)
    {
        string availability = skirt.get_availability() ? "available" : "unavailable";

        string display_text = skirt.get_name() + "| " +skirt.get_size() + "| " + std::to_string(skirt.get_price()) + " " + availability;

        auto *item = new QListWidgetItem(QString::fromStdString(display_text));

        item->setBackground(skirt.get_availability() ? Qt::green : Qt::red);

        skirts_list->addItem(item);
    }
}



