//
// Created by octav on 02.04.2026.
//

#ifndef LAB4_UI_H
#define LAB4_UI_H
#include "../Service/MedService.h"

class UI
{
private:
    /*
     * service used by UI
     */
    MedService& serv;

public:
    /*
     * Creates UI
     * :param serv: service reference
     */
    UI(MedService& serv) : serv{serv}{}

    /*
     * Starts the application
     */
    void startUI() const;
};



#endif //LAB4_UI_H