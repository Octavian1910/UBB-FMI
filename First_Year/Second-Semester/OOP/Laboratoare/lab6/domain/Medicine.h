#ifndef LAB4_MEDICINE_H
#define LAB4_MEDICINE_H
#include <string>
#include <iostream>
#include <utility>
using std::string;
using std::cout;


class Medicine
{
private:
    /*
     * name: the name of the medicine
     * price: the price
     * producer: the producer
     * active_substance: the active substance
     */
    string  name;
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
    Medicine(string name,int price,string producer,string active_substance):name{std::move(name)},price{price},producer{std::move(producer)},active_substance{std::move(active_substance)}{};


    Medicine(const Medicine& ot)
    : name{ot.name}, price{ot.price}, producer{ot.producer}, active_substance{ot.active_substance}
    {
        std::cout << "Copy constructor called!\n";
    }

    Medicine& operator=(const Medicine& ot)
    {
        std::cout << "Assignment operator called!\n";
        if (this != &ot)
        {
            name = ot.name;
            price = ot.price;
            producer = ot.producer;
            active_substance = ot.active_substance;
        }
        return *this;
    }

    /*
     * Gets the name
     * :return: name
     */
    [[nodiscard]] string get_name() const;

    /*
     * Gets the price
     * :return: price
     */
    [[nodiscard]] int get_price() const;

    /*
     * Gets the producer
     * :return: producer
     */
    [[nodiscard]] string get_producer() const;

    /*
     * Gets the active substance
     * :return: substance
     */
    [[nodiscard]] string get_active_substance() const;

    /*
     * Gets the ID (name|producer)
     * :return: id
     */
    [[nodiscard]] string get_ID() const;

    /*
     * Sets new name
     * :param new_name: new name
     */
    void set_name(string new_name);

    /*
     * Sets new price
     * :param price: new price
     */
    void set_price(int price);

    /*
     * Sets new producer
     * :param new_producer: new producer
     */
    void set_producer(string new_producer);

    /*
     * Sets new active substance
     * :param new_active_substance: new substance
     */
    void set_active_substance(string new_active_substance);
};

#endif //LAB4_MEDICINE_H