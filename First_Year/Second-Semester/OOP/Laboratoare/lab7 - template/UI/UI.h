#pragma once

#include "../service/MedService.h"

class UI {
private:
    MedService& serv;

public:
    UI(MedService& serv) : serv{ serv } {}

    void startUI() const;
};