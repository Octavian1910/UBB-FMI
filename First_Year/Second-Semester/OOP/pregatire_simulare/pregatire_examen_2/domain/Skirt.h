//
// Created by octav on 20.05.2026.
//

#ifndef PREGATIRE_EXAMEN_2_SKIRT_H
#define PREGATIRE_EXAMEN_2_SKIRT_H
#include <string>
using std::string;

class Skirt
{
private:
    string name;
    int ID;
    int price;
    string size;
    bool availability;
public:
    Skirt(int ID,string name,string size,int price,bool availability):ID{ID},name{name},size{size},price{price},availability{availability}{}
    const string& get_name() const;
    const string& get_size() const;
    int get_price() const;
    int get_ID() const;
    bool get_availability() const;
    void set_availability(bool status);
};


#endif //PREGATIRE_EXAMEN_2_SKIRT_H