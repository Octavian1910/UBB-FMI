#ifndef UI_H_
#define UI_H_

#include "../service/service.h"

/*
 Reprezinta interfata utilizatorului
*/
typedef struct
{
    ServiceFarmacie* service;
} UI;


/*
 Creeaza interfata utilizatorului

 :param s: pointer la service

 :return: pointer la obiect UI alocat dinamic

 :pre:
 s != NULL

 :post:
 se aloca memorie pentru UI
 UI contine pointer la service
*/
UI creeazaUI(ServiceFarmacie* s);





/*
 Ruleaza meniul aplicatiei

 :param ui: pointer la UI

 :return: pointer la UI

 :pre:
 ui != NULL

 :post:
 utilizatorul poate executa operatiile aplicatiei
 aplicatia ruleaza pana la alegerea optiunii de iesire
*/
void ruleazaUI(UI* ui);


#endif