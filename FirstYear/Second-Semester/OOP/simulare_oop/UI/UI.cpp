//
// Created by octav on 22.05.2026.
//

#include "UI.h"
#include <QHBoxLayout>
#include <QFormLayout>


UI::UI(Service &service):service{service}
{
    QHBoxLayout* mainLay = new QHBoxLayout(this);

    mainLay->addWidget(lista_postari);

    auto* formLay = new QFormLayout;
    formLay->addRow("Cod postare :",cod_postare);
    formLay->addRow("Tip continut : ",tip_continut);
    mainLay->addLayout(formLay);

    QVBoxLayout* buttonsLay = new QVBoxLayout;
    buttonsLay->addWidget(sort_by_creator_ascending);
    buttonsLay->addWidget(sort_by_creator_descending);
    buttonsLay->addWidget(sort_by_platform_ascending);
    buttonsLay->addWidget(sort_by_platform_descending);
    buttonsLay->addWidget(unsort);
    mainLay->addLayout(buttonsLay);


   connect_buttons();

    load_data(service.get_all());
}

void UI::load_data(vector<Postare> to_load)
{
    lista_postari->clear();
    displayed = to_load;
    auto& result = to_load;
    for (auto& elem:result)
    {
        string text = elem.get_creator()+" | " + elem.get_platforma();
        auto* item = new QListWidgetItem(QString::fromStdString(text));
        string tool_tip = "Platforma pentru ...";

        if (elem.get_platforma() == "Instagram")
        {
            tool_tip = "Platforma pentru reels,stories si postari vizuale";
        }
        if (elem.get_platforma() == "TikTok")
        {
            tool_tip = "Platforma pentru videoclipuri scurte si trenduri virale";
        }
        if (elem.get_platforma() == "BeReal")
        {
            tool_tip = "Platforma pentru postari spontane si autentice";
        }
        item->setToolTip(QString::fromStdString(tool_tip));
        lista_postari->addItem(item);
    }
}

int UI::get_index()
{
    int index = lista_postari->currentRow();
    if (index < 0)
        return -1;

    return index;
}

void UI::connect_buttons()
{
    QObject::connect(sort_by_creator_ascending,&QPushButton::clicked,
        [this]()
        {
           load_data(service.sort_by_creator(true));
        });

    QObject::connect(sort_by_creator_descending,&QPushButton::clicked,
        [this]()
        {
           load_data(service.sort_by_creator(false));
        });


    QObject::connect(sort_by_platform_ascending,&QPushButton::clicked,
        [this]()
        {
           load_data(service.sort_by_platform(true));
        });

    QObject::connect(sort_by_platform_descending,&QPushButton::clicked,
        [this]()
        {
           load_data(service.sort_by_platform(false));
        });

    QObject::connect(unsort,&QPushButton::clicked,
        [this]()
        {
           load_data(service.get_all());
        });

    QObject::connect(lista_postari,&QListWidget::itemSelectionChanged,
        [this]()
        {
           int index = get_index();
            Postare post = displayed.at(index);
            cod_postare->setText(QString::fromStdString(std::to_string(post.get_cod())));
            tip_continut->setText(QString::fromStdString(post.get_tip()));

        });
}