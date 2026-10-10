//
// Created by octav on 01.04.2026.
//

#include "UI.h"
#include "../repository/PetRepo.h"
#include "../service/PetStore.h"
#include <iostream>
using std::cin;
using std::cout;

void UI::startUI()
{
    while (true)
    {
        cout <<"1) ADD \n2) Print \n3)Exit\n Comanda: ";
        int comanda = 0;
        cin>>comanda;
        if (comanda == 0)
        {
            break;
        }
        if (comanda == 1)
        {
            //citim
            string type;
            string species;
            double price;
            cout << "Type ";
            cin >> type;
            cout << "Species ";
            cin >> species;
            cout << "Price ";
            cin >> price;
            try
            {
                serv.add(type,species,price);
                cout << "Pet added\n";
            }
            catch (RepoException & ex)
            {
                cout << ex.getMessage();
            }
        }
    }
}
