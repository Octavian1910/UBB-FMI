//
// Created by octav on 21.05.2026.
//

#ifndef SIMULARE_EX_MASINA_CAR_H
#define SIMULARE_EX_MASINA_CAR_H
#include <string>

using std::string;


class Car
{
private:
    int id;
    string brand;
    string model;
    int age;
public:
    Car(int id,const string& brand,const string& model,int age):id{id},brand{brand},model{model},age{age}{}
    const string& get_model() const;
    const string& get_brand() const;
    int get_ID() const;
    int get_age() const;
};


#endif //SIMULARE_EX_MASINA_CAR_H