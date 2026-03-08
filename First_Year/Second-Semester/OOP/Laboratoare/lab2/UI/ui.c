#include "ui.h"
#include <stdlib.h>
#include <stdio.h>


UI* creeazaUI(ServiceFarmacie* s)
{
    UI* ui = malloc(sizeof(UI));
    ui->service = s;
    return ui;
}

void distrugeUI(UI* ui)
{
    distruge_service_farmacie(ui->service);
    free(ui);
}

void meniu()
{
    printf("\n--- GESTIUNE FARMACIE ---\n");
    printf("1. Adaugare/Actualizare medicament\n");
    printf("2. Actualizare (nume, concentratie)\n");
    printf("3. Stergere stoc pentru un anumit medicament\n");
    printf("4. Vizualizare stoc\n");
    printf("0. Iesire\n");
    printf("Comanda: ");
}


UI* ruleazaUI(UI* ui)
{
    while (1 == 1)
    {
        meniu();
        int comanda = 0;
        scanf("%d",&comanda);
        switch (comanda)
        {
            case(1):
            {
                int cod,concentratie,cantitate;
                char nume[50];
                printf("Cod : "); int r1 = scanf("%d",&cod);
                printf("Nume : "); int r2 = scanf("%s",nume);
                printf("Concentratie : "); int r3 = scanf("%d",&concentratie);
                printf("Cantitate : "); int r4 = scanf("%d",&cantitate);
                if (r1 == 0 || r2 == 0 || r3 == 0 || r4 == 0 )
                {
                    printf("Tipul de date nu este bun!\n");
                }
                else
                {
                    int mesaj = adaugaService(ui->service,cod,nume,concentratie,cantitate);
                    if (mesaj == 0)
                        printf("A fost adaugat/actualizat! \n");
                    else if (mesaj == 1)
                        printf("Codul nu este un numar pozitiv!\n");
                    else if (mesaj == 2)
                        printf("Numele este vid\n");
                    else if (mesaj == 3)
                        printf("Concentratia este negativa! \n");
                    else if (mesaj == 4)
                        printf("Cantitatea este negativa! \n");
                    }
                    break;
            }

            case(2):
            {
                int cod,concentratie;
                char nume[50];
                printf("Cod : "); int r1 = scanf("%d",&cod);
                printf("Nume : "); int r2 = scanf("%s",nume);
                printf("Concentratie : "); int r3 = scanf("%d",&concentratie);
                if (r1 == 0 || r2 == 0 || r3 == 0 )
                {
                    printf("Tipul de date nu este bun!\n");

                }
                else
                {
                    int mesaj = actualizeazaService(ui->service,cod,nume,concentratie);

                    if (mesaj == 0)
                        printf("Totul a mers bine.\n");
                    else if (mesaj == -1)
                        printf("Nu exista acest element!\n");
                    else if (mesaj == 1)
                        printf("Codul nu este un numar pozitiv!\n");
                    else if (mesaj == 2)
                        printf("Numele este vid\n");
                    else if (mesaj == 3)
                        printf("Concentratia este negativa! \n");
                    else if (mesaj == 4)
                        printf("Cantitatea este negativa! \n");
                }
                break;
            }
            case(3):
            {
                int cod = 0;
                printf("Cod : "); scanf("%d",&cod);
                int mesaj = sterge_service(ui->service,cod);
                if (mesaj == 0)
                {
                    printf("Stocul a fost sters!\n");
                }
                else printf("Stocul nu a fost sters!\n");

                break;
            }
            case(4):
            {

                break;
            }

            default: return 0;
        }
    }


}