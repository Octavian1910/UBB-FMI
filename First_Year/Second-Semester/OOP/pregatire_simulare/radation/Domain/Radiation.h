//
// Created by octav on 21.05.2026.
//

#ifndef RADATION_RADIATION_H
#define RADATION_RADIATION_H
#include <string>
using std::string;

class Radiation
{
private:
    //radation(int id,string description,float frequency,string type_frequency)
    int ID;
    string description;
    float frequency;
    string type_frequency;
public:
    Radiation(int ID,const string& description,float frequency,const string& type_frequency):ID(ID),description(description),frequency{frequency},type_frequency(type_frequency){}
    const int get_ID() const;
    const string& get_description() const;
    const string& get_type_frequency() const;
    float get_frequency() const;
};


#endif //RADATION_RADIATION_H