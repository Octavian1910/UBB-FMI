//
// Created by octav on 01.04.2026.
//

#ifndef LAB4_UI_H
#define LAB4_UI_H

#include "../service/PetStore.h"
class UI
{
private:
    PetStore& serv;
public:
    UI(PetStore& serv) : serv{serv}{}
    void startUI();
};


#endif //LAB4_UI_H