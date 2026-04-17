//
// Created by octav on 31.03.2026.
//

#ifndef LAB4_PET_H
#define LAB4_PET_H
#include <string>
using std::string;


class Pet
{
private:
	string type;
	string species;
	double price;
public:
	double get_price() const
	{
	return price;
	}
	string getType() const;
	string getSpecies() const;
    Pet(string type,string species,double pr):type{type},species{species},price{pr}{}
    Pet(const Pet& ot):type{ot.type},species{ot.species},price{ot.price}{}
};


#endif //LAB4_PET_H