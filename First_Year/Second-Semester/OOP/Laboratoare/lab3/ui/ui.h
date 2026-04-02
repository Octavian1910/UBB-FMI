#ifndef UI_H
#define UI_H

#include "../service/service.h"

typedef struct {
    ServiceCheltuieli* service;
}UI;

void afiseaza_meniu();
int optiune();
UI* creeaza_ui(ServiceCheltuieli* s);
void distruge_ui(UI* ui);
void start(UI* ui);

#endif