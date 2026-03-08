#ifndef UI_H_
#define UI_H_
#include "../service/service.h"

typedef struct
{
    ServiceFarmacie* service;
}UI;

UI* creeazaUI(ServiceFarmacie* s);
void distrugeUI(UI* ui);
UI* ruleazaUI(UI* ui);

#endif
