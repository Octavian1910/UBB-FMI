#include <iostream>

#include "CP.h"

using namespace std;


bool relatieBurse(TPrioritate p1,TPrioritate p2)
{
    return p1 >= p2; //descrescator
}

int main()
{
    CP coadaBurse(relatieBurse);

    cout << "Se introduc datele studentiilor \n";

    coadaBurse.adauga(101,8);
    coadaBurse.adauga(100,9);
    coadaBurse.adauga(105,10);
    coadaBurse.adauga(102,2);
    coadaBurse.adauga(103,12);
    coadaBurse.adauga(104,5);

    int burse_acordate = 3;
    while (burse_acordate--)
    {
        Element sef = coadaBurse.sterge();
        cout << sef.first << " - " << sef.second << "\n";
    }
    return 0;

}