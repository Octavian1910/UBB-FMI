#include "ui.h"
#include "../service/service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afiseaza_meniu() {
    printf("===MENIU===\n");
    printf("1. Adauga cheltuiala\n");
    printf("2. Modifica cheltuiala\n");
    printf("3. Afisare cheltuieli\n");
    printf("4. Sterge cheltuiala\n");
    printf("5. Ordoneaza dupa suma crescator\n");
    printf("6. Ordoneaza dupa suma descrescator\n");
    printf("7. Ordoneaza dupa tip crescator\n");
    printf("8. Ordoneaza dupa tip descrescator\n");
    printf("9. Filtreaza dupa suma\n");
    printf("10. Filtreaza dupa zi\n");
    printf("11. Filtreaza dupa tip\n");
    printf("12. Filtreaza dupa interval de zile\n");
    printf("13. Undo\n");
    printf("14. Sterge dupa zi\n");
    printf("0. Iesire\n");
}

int optiune() {
    printf("Alege optiunea: ");
    int o;
    scanf("%d",&o);
    return o;
}

UI* creeaza_ui(ServiceCheltuieli* s) {
    UI* ui = malloc(sizeof(UI));
    ui->service = s;
    return ui;
}

void distruge_ui(UI* ui) {
    distruge_service(ui->service);
    free(ui);
}

void afiseaza_lista(MyList* lista) {
    for (int i = 0; i < size(lista); i++) {
        Cheltuiala* c = (Cheltuiala*)get(lista, i);
        printf("%d. ziua: %d, suma: %.2f, tipul: %s\n",
               get_id(c), get_zi(c), get_suma(c), get_tip(c));
    }
}

void start(UI* ui) {
    while (1) {
        afiseaza_meniu();
        int opt = optiune();

        if (opt == 0)
            break;

        if (opt == 1) {
            int id, zi;
            float suma;
            char tip[50];

            printf("Introduceti id-ul: "); scanf("%d",&id);
            printf("Introduceti ziua: "); scanf("%d",&zi);
            printf("Introduceti suma: "); scanf("%f",&suma);
            printf("Introduceti tipul: "); scanf("%s",tip);

            int erori = adauga_service(ui->service,id,zi,suma,tip);
            if (erori==1) printf("Exista deja o cheltuiala\n");
            if (erori==2) printf("Zi invalida\n");
            if (erori==3) printf("Suma invalida\n");
            if (erori==0) printf("Succes\n");
        }

        else if (opt == 2) {
            int id, zi;
            float suma;
            char tip[50];

            printf("ID: "); scanf("%d",&id);
            printf("Zi: "); scanf("%d",&zi);
            printf("Suma: "); scanf("%f",&suma);
            printf("Tip: "); scanf("%s",tip);

            int erori = modifica_cheltuiala_service(ui->service,id,zi,suma,tip);
            if (erori==1) printf("Nu exista\n");
            if (erori==2) printf("Zi invalida\n");
            if (erori==3) printf("Suma invalida\n");
            if (erori==0) printf("Succes\n");
        }

        else if (opt == 3) {
            MyList* lista = get_all_service(ui->service);

            for (int i = 0; i < size(lista); i++) {
                Cheltuiala* c = (Cheltuiala*)get(lista, i);
                printf("%d. ziua: %d, suma: %.2f, tipul: %s\n",
                       get_id(c), get_zi(c), get_suma(c), get_tip(c));
            }
        }

        else if (opt == 4) {
            int id;
            printf("ID : \n"); scanf("%d",&id);
            if (sterge_cheltuiala_service(ui->service,id)==-1)
                printf("Nu exista\n");
            else
                printf("Sters\n");
        }


        else if (opt >= 5 && opt <= 8) {
            int criteriu = (opt <= 6) ? 1 : 2;
            int ordine = (opt % 2 == 1) ? 1 : 2;

            MyList* lista = sorteaza_service(ui->service, criteriu, ordine);
            afiseaza_lista(lista);
            destroyList(lista, NULL);
        }


        else if (opt == 9) {
            float suma;
            scanf("%f",&suma);

            MyList* lista = filtrare_dupa_suma(ui->service, suma);
            afiseaza_lista(lista);
            destroyList(lista, NULL);
        }

        else if (opt == 10) {
            int zi;
            scanf("%d",&zi);

            MyList* lista = filtrare_dupa_zi(ui->service, zi);
            afiseaza_lista(lista);
            destroyList(lista, NULL);
        }

        else if (opt == 11) {
            char tip[50];
            scanf("%s",tip);

            MyList* lista = filtrare_dupa_tip(ui->service, tip);
            afiseaza_lista(lista);
            destroyList(lista, NULL);
        }

        else if (opt == 12) {
            int a,b;
            scanf("%d %d",&a,&b);

            MyList* lista = filtrare_interval_zile(ui->service, a, b);
            afiseaza_lista(lista);
            destroyList(lista, NULL);
        }
        else if (opt == 13) {
            if (undo(ui->service) == -1)
                printf("Nu mai exista operatii de undo!\n");
            else
                printf("Undo realizat cu succes!\n");
        }
        else if (opt == 14) {
            int zi;
            printf("Zi :"); scanf("%d",&zi);
            int nr_zile_sterse = sterge_dupa_zi(ui->service, zi);
            printf("S-au sters %d cheltuieli.\n",nr_zile_sterse);
        }

        else {
            printf("Optiune invalida\n");
        }
    }
}