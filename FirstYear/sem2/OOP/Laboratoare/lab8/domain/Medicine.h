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
    string name;
    int price;
    string producer;
    string active_substance;
public:
    Medicine(string name,int price,string producer,string active_substance):name{std::move(name)},price{price},producer{std::move(producer)},active_substance{std::move(active_substance)}{}

    Medicine(const Medicine& ot):name{ot.name},price{ot.price},producer{ot.producer},active_substance{ot.active_substance}
    {
        //std::cout << "Copy constructor called!\n";
    }

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



    const string& get_name() const;
    int get_price() const;
    const string& get_active_substance() const;
    const string& get_producer() const;
    string get_ID() const;

    void set_name(const string& new_name);
    void set_price(int new_price);
    void set_active_substance(const string& new_active_substance);
    void set_producer(const string& new_producer);

};


#endif //LAB5_IT1_MEDICINE_H