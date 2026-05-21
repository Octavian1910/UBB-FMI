#include "UI.h"
#include "../Repository/RepositoryException.h"
#include "../domain/Validator/ValidatorException.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

void show_ui()
{
    cout << "==MENU==\n";
    cout << "1)ADD medicine\n";
    cout << "2)VIEW medicines\n";
    cout << "3)UPDATE medicine\n";
    cout << "4)DELETE medicine\n";
    cout << "5)FIND medicine\n";
    cout << "6)FILTER BY\n";
    cout << "7)SORT BY\n";
    cout << "8)EXIT\n";
}

template<typename T>
T read_value(const string& msg)
{
    T value;
    while (true)
    {
        cout << msg;
        if (cin >> value)
            return value;

        cout << "Invalid type!\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void UI::startUI() const
{
    bool run = true;
    while (run)
    {
        show_ui();
        try
        {

            switch (read_value<int>("\nOPTION : "))
            {
                case 1:
                {
                    auto name = read_value<string>("Name : ");
                    int price = read_value<int>("Price : ");
                    auto producer = read_value<string>("Producer : ");
                    auto active_substance = read_value<string>("Substance : ");
                    serv.store(name,price,producer,active_substance);
                    cout << "Medicine stored successfully!\n";
                    break;
                }

                case 2:
                {
                    const auto& respone = serv.getAll();
                    for (const auto& med:respone)
                    {
                        cout<<"Name: " << med.get_name()
                            << " Price: " << med.get_price()
                            << " Producer: " << med.get_producer()
                            << " Active Substance: " << med.get_active_substance() << "\n";
                    }
                    cout << "Medicines displayed successfully!\n";
                    break;
                }

                case 3:
                {
                    auto name = read_value<string>("Name : ");
                    int price = read_value<int>("Price : ");
                    auto producer = read_value<string>("Producer : ");
                    auto active_substance = read_value<string>("Substance : ");
                    serv.update(name,price,producer,active_substance);
                    cout << "Medicine updated successfully!\n";
                    break;
                }

                case 4:
                {
                    auto name = read_value<string>("Name : ");
                    auto producer = read_value<string>("Producer : ");
                    string ID = name;
                    ID += "|";
                    ID += producer;
                    serv.remove(ID);
                    cout << "Medicine removed successfully!\n";
                    break;
                }

                case 5:
                {
                    auto name = read_value<string>("Name : ");
                    auto producer = read_value<string>("Producer : ");
                    string ID = name;
                    ID += "|";
                    ID += producer;
                    const Medicine& med = serv.find(ID);
                    cout<<"Name: " << med.get_name()
                        << " Price: " << med.get_price()
                        << " Producer: " << med.get_producer()
                        << " Active Substance: " << med.get_active_substance() << "\n";
                    break;
                }

                case 6: // FILTER
                {
                    int temp_option = read_value<int>("1)Price 2)Active Substance : ");

                    if (temp_option == 1)
                    {
                        int price = read_value<int>("Price: ");
                        const auto& respone = serv.filterByPrice(price);

                        for (const auto* med:respone)
                        {
                            cout<<"Name: " << med->get_name()
                                << " Price: " << med->get_price()
                                << " Producer: " << med->get_producer()
                                << " Active Substance: " << med->get_active_substance() << "\n";
                        }
                    }
                    else
                    {
                        auto substance = read_value<string>("Substance: ");
                        const auto& respone = serv.filterBySubstance(substance);

                        for (const auto* med:respone)
                        {
                            cout<<"Name: " << med->get_name()
                                << " Price: " << med->get_price()
                                << " Producer: " << med->get_producer()
                                << " Active Substance: " << med->get_active_substance() << "\n";
                        }
                    }

                    cout << "Medicines displayed with filter successfully!\n";
                    break;
                }

                case 7: // SORT
                {
                    int temp_option = read_value<int>("1)Name 2)Producer 3)Active Substance : ");
                    bool ascending = read_value<bool>("0)Descending 1)Ascending : ");

                    vector<const Medicine*> respone;

                    switch (temp_option)
                    {
                        case 1:
                            respone = serv.sortByName(ascending);
                            break;
                        case 2:
                            respone = serv.sortByProducer(ascending);
                            break;
                        case 3:
                            respone = serv.sortByActiveSubstance(ascending);
                            break;
                        default:
                            cout<<"The option is not valid!";
                            continue;
                    }

                    for (const auto* med:respone)
                    {
                        cout<<"Name: " << med->get_name()
                            << " Price: " << med->get_price()
                            << " Producer: " << med->get_producer()
                            << " Active Substance: " << med->get_active_substance() << "\n";
                    }

                    cout << "Medicines displayed sorted successfully!\n";
                    break;
                }

                default:
                {
                    run = false;
                    cout << "Good bye!\n";
                    break;
                }
            }
        }
        catch (RepositoryException& e)
        {
            cout << e.getMessage();
        }
        catch (ValidatorException& e)
        {
            cout << e.getMessage();
        }
    }
}