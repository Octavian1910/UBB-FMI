//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_MEDICINE_H
#define LAB5_IT1_MEDICINE_H
#include <string>
#include <iostream>
#include <utility>

using std::string;

class Medicine
{
private:
    /*
     * name: medicine name
     * price: medicine price
     * producer: producer name
     * active_substance: active substance
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
    Medicine(string name,int price,string producer,string active_substance):name{std::move(name)},price{price},producer{std::move(producer)},active_substance{std::move(active_substance)}{}

    /*
     * Copy constructor
     * :param ot: other medicine
     */
    Medicine(const Medicine& ot):name{ot.name},price{ot.price},producer{ot.producer},active_substance{ot.active_substance}
    {
        //std::cout << "Copy constructor called!\n";
    }

    /*
     * Assignment operator
     * :param ot: other medicine
     * :return: current object
     */
    Medicine& operator=(const Medicine& ot)
    {
        //std::cout<<"Assignment operator called\n";
        if (this != &ot)
        {
            this->name = ot.name;
            this->price = ot.price;
            this->active_substance = ot.active_substance;
            this->producer = ot.producer;
        }
        return *this;
    }


    /*
     * Gets the medicine name
     * :return: medicine name
     */
    const string& get_name() const;

    /*
     * Gets the medicine price
     * :return: medicine price
     */
    int get_price() const;

    /*
     * Gets the active substance
     * :return: active substance
     */
    const string& get_active_substance() const;

    /*
     * Gets the producer
     * :return: producer name
     */
    const string& get_producer() const;

    /*
     * Gets the medicine ID
     * :return: medicine ID
     */
    string get_ID() const;

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
     * :param new_producer: new producer name
     */
    void set_producer(const string& new_producer);

};


#endif //LAB5_IT1_MEDICINE_H