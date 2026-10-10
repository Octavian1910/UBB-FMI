//
// Created by octav on 01.05.2026.
//

#ifndef LAB5_IT1_UI_H
#define LAB5_IT1_UI_H
#include "../Service/MedService.h"

class UI
{
private:
    /*
     * serv: medicine service
     */
    MedService& serv;

public:
    /*
     * Creates UI
     * :param serv: medicine service
     */
    UI(MedService& serv) : serv{serv} {}

    /*
     * Starts UI
     */
    void startUI() const;
};

#endif //LAB5_IT1_UI_H