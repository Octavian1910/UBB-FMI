#pragma once
#include <string>
#include <iostream>
#include <utility>

using std::string;

class Medicine
{
private:
    /*
     * name: the name of the medicine
     * price: the price
     * producer: the producer
     * active_substance: the active substance
     */
    string name;
    int price;
    string producer;
    string active_substance;

public:
    /*
     * Creates a medicine
     * :param name: medicine name
     * :param price: medicine price
     * :param producer: producer name
     * :param active_substance: active substance
     */
    Medicine(string name, int price, string producer, string active_substance)
        : name{std::move(name)},
          price{price},
          producer{std::move(producer)},
          active_substance{std::move(active_substance)} {}

    /*
     * Copy constructor for Medicine
     * :param ot: medicine object to copy
     */
    Medicine(const Medicine& ot)
        : name{ot.name},
          price{ot.price},
          producer{ot.producer},
          active_substance{ot.active_substance}
    {
        // std::cout << "Copy constructor called!\n";
    }

    /*
     * Assignment operator for Medicine
     * :param ot: medicine object to assign
     * :return: reference to current object
     */
    Medicine& operator=(const Medicine& ot)
    {
        // std::cout << "Assignment operator called!\n";

        if (this != &ot)
        {
            name = ot.name;
            price = ot.price;
            active_substance = ot.active_substance;
            producer = ot.producer;
        }

        return *this;
    }

    /*
     * Gets the medicine name
     * :return: medicine name
     */
    [[nodiscard]] const string& get_name() const;

    /*
     * Gets the medicine price
     * :return: medicine price
     */
    [[nodiscard]] int get_price() const;

    /*
     * Gets the active substance
     * :return: active substance
     */
    [[nodiscard]] const string& get_active_substance() const;

    /*
     * Gets the producer
     * :return: producer name
     */
    [[nodiscard]] const string& get_producer() const;

    /*
     * Gets the medicine ID (name|producer)
     * :return: medicine ID
     */
    [[nodiscard]] string get_ID() const;

    /*
     * Sets a new medicine name
     * :param new_name: new medicine name
     */
    void set_name(const string& new_name);

    /*
     * Sets a new medicine price
     * :param new_price: new medicine price
     */
    void set_price(int new_price);

    /*
     * Sets a new active substance
     * :param new_active_substance: new active substance
     */
    void set_active_substance(const string& new_active_substance);

    /*
     * Sets a new producer
     * :param new_producer: new producer
     */
    void set_producer(const string& new_producer);
};