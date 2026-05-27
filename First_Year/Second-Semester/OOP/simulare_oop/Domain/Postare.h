//
// Created by octav on 22.05.2026.
//

#ifndef SIMULARE_OOP_POSTARE_H
#define SIMULARE_OOP_POSTARE_H
#include <string>
using std::string;

class Postare
{
private:
    int cod;
    string creator;
    string tip;
    string platforma;
public:
    /*Constructor*/
    Postare(int cod,string creator,string tip,string platforma):cod{cod},creator{creator},tip{tip},platforma{platforma}{}

    /*Returneaza codul postarii
     * returns: int
     */
    int get_cod() const;


    /*returns: creator string */
    const string& get_creator() const;

    /*returns: tip string */
    const string& get_tip() const;

    /*returns: platforma string */
    const string& get_platforma() const;
};


#endif //SIMULARE_OOP_POSTARE_H