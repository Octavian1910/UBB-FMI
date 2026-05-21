#include "ui.h"
#include <stdlib.h>
#include <stdio.h>


void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int citesteInt(const char* mesaj)
{
    int x;
    int r;

    while (1)
    {
        printf("%s", mesaj);
        r = scanf("%d", &x);

        if (r == 1)
        {
            clearInputBuffer();
            return x;
        }

        printf("Tip de date invalid! Introdu un numar!\n");
        clearInputBuffer();
    }
}

void citesteString(const char* mesaj, char* s)
{
    printf("%s", mesaj);
    scanf("%49s", s);
    clearInputBuffer();
}


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
    printf("4. Vizualizare medicamente\n");
    printf("5. Vizualizare medicamente dupa stoc, ordonat\n");
    printf("6. Filtrare medicamente\n");
    printf("0. Iesire\n");
}

UI* ruleazaUI(UI* ui)
{
    while (1)
    {
        meniu();

        int comanda = citesteInt("Comanda: ");

        switch (comanda)
        {
            case 1:
            {
                int cod, concentratie, cantitate;
                char nume[50];

                cod = citesteInt("Cod: ");
                citesteString("Nume: ", nume);
                concentratie = citesteInt("Concentratie: ");
                cantitate = citesteInt("Cantitate: ");

                int mesaj = adaugaService(ui->service, cod, nume, concentratie, cantitate);

                if (mesaj == 0)
                    printf("A fost adaugat/actualizat!\n");
                else if (mesaj == 1)
                    printf("Codul nu este pozitiv!\n");
                else if (mesaj == 2)
                    printf("Numele este vid!\n");
                else if (mesaj == 3)
                    printf("Concentratia este negativa!\n");
                else if (mesaj == 4)
                    printf("Cantitatea este negativa!\n");

                break;
            }

            case 2:
            {
                int cod, concentratie;
                char nume[50];

                cod = citesteInt("Cod: ");
                citesteString("Nume: ", nume);
                concentratie = citesteInt("Concentratie: ");

                int mesaj = actualizeazaService(ui->service, cod, nume, concentratie);

                if (mesaj == 0)
                    printf("Actualizare realizata.\n");
                else if (mesaj == -1)
                    printf("Elementul nu exista!\n");
                else if (mesaj == 1)
                    printf("Cod invalid!\n");
                else if (mesaj == 2)
                    printf("Nume invalid!\n");
                else if (mesaj == 3)
                    printf("Concentratie invalida!\n");

                break;
            }

            case 3:
            {
                int cod = citesteInt("Cod: ");

                int mesaj = sterge_service(ui->service, cod);

                if (mesaj == 0)
                    printf("Stocul a fost sters!\n");
                else
                    printf("Medicamentul nu exista!\n");

                break;
            }

            case 4:
            {
                Medicament** rezultat = get_all_service(ui->service);
                int lungime = nr_medicamente_service(ui->service);

                if (lungime == 0)
                {
                    printf("Nu exista elemente!\n");
                }
                else
                {
                    printf("\nCod | Nume | Concentratie | Cantitate\n");

                    for (int i = 0; i < lungime; i++)
                    {
                        Medicament* curent = rezultat[i];

                        printf("%d %s %d %d\n",
                               get_cod(curent),
                               get_nume(curent),
                               get_concentratie(curent),
                               get_cantitate(curent));
                    }
                }

                free(rezultat);
                break;
            }

            case 5:
            {
                int criteriu = citesteInt("1) Nume\n2) Cantitate\n");
                int ordine_citita = citesteInt("1) Crescator\n2) Descrescator\n");
                int ordine = 0;
                if (ordine_citita != 1)
                {
                    ordine = 0;
                }

                int lungime = 0;
                Medicament** rezultat = NULL;

                if (criteriu == 1)
                {
                    // Pasăm funcția comparaNume ca parametru
                    rezultat = sortareMedicamente(ui->service, comparaNume, ordine, &lungime);
                }
                else
                {
                    // Pasăm funcția comparaCantitate ca parametru
                    rezultat = sortareMedicamente(ui->service, comparaCantitate, ordine, &lungime);
                }

                printf("\n");
                if (lungime == 0)
                {
                    printf("Nu exista elemente!\n");
                }
                else
                {
                    for (int i = 0; i < lungime; i++)
                    {
                        Medicament* curent = rezultat[i];
                        // Afișăm detaliile folosind getterii din domain
                        printf("Cod: %d | Nume: %s | Concentratie: %d | Cantitate: %d\n",
                               get_cod(curent),
                               get_nume(curent),
                               get_concentratie(curent),
                               get_cantitate(curent));
                    }
                }

                // Eliberăm doar vectorul de pointeri alocat în service/repo, nu și medicamentele în sine
                free(rezultat);
                break;
            }
            case(6):
            {
                int criteriu = citesteInt("Criteriu:  1) mai mic decat un nr dat 2) care au prima litera ");
                char valoare[50];
                citesteString("Introdu nr/prima_litera",valoare);
                int lungime = 0;
                Medicament** rezultat = filtrareMedicamente(ui->service,criteriu,valoare,&lungime);
                printf("\n");
                if (lungime == 0)
                {
                    printf("Nu exista elemente!\n");
                }
                else
                {
                    for (int i = 0; i < lungime; i++)
                    {
                        Medicament* curent = rezultat[i];

                        printf("%d %s %d %d\n",
                               get_cod(curent),
                               get_nume(curent),
                               get_concentratie(curent),
                               get_cantitate(curent));
                    }
                }
                    free(rezultat);
                break;
            }

            case 0:
                return ui;

            default:
                printf("Comanda invalida!\n");
        }
    }
}