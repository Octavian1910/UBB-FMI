#include "service.h"
#include <stdlib.h>
#include <string.h>

void salveazaUndo(const ServiceCheltuieli* s) {
    RepoCheltuieli* copie = copiaza_repo(s->repo);
    add(s->undoList, copie);
}

int undo(ServiceCheltuieli* s) {
    if (size(s->undoList) == 0)
        return -1;

    distruge_repo(s->repo);
    s->repo = (RepoCheltuieli*)removeLast(s->undoList);

    return 0;
}

ServiceCheltuieli* creeaza_service(RepoCheltuieli* r) {
    ServiceCheltuieli* s = malloc(sizeof(ServiceCheltuieli));
    s->repo = r;
    s->undoList = createList();
    return s;
}

Cheltuiala* cauta_cheltuiala_service(const ServiceCheltuieli* s, int id) {
    return cauta_cheltuiala_repo(s->repo, id);
}

int adauga_service(const ServiceCheltuieli* s, int id, int zi, float suma, char* tip) {
    if (cauta_cheltuiala_repo(s->repo, id) != NULL) return 1;
    if (zi < 1 || zi > 31) return 2;
    if (suma < 0) return 3;

    salveazaUndo(s);

    Cheltuiala* c = creeaza_cheltuiala(id, zi, suma, tip);
    adauga_repo(s->repo, c);
    return 0;
}

int modifica_cheltuiala_service(const ServiceCheltuieli* s, int id, int zi, float suma, char* tip) {
    if (cauta_cheltuiala_repo(s->repo, id) == NULL) return 1;
    if (zi < 1 || zi > 31) return 2;
    if (suma < 0) return 3;

    salveazaUndo(s);

    Cheltuiala* nou = creeaza_cheltuiala(id, zi, suma, tip);
    modifica_cheltuiala_repo(s->repo, nou);

    return 0;
}

int sterge_cheltuiala_service(const ServiceCheltuieli* s, int id) {
    if (cauta_cheltuiala_repo(s->repo, id) == NULL)
        return -1;

    salveazaUndo(s);

    return sterge_cheltuiala_repo(s->repo, id);
}

int get_nr_cheltuieli(const ServiceCheltuieli* s) {
    return get_lungime_repo(s->repo);
}

MyList* get_all_service(const ServiceCheltuieli* s) {
    return get_all(s->repo);
}

int compara_suma_crescator(const Cheltuiala* c1,const Cheltuiala* c2) {
    return get_suma(c1) > get_suma(c2);
}

int compara_suma_descrescator(const Cheltuiala* c1,const Cheltuiala* c2) {
    return get_suma(c1) < get_suma(c2);
}

int compara_tip_crescator(const Cheltuiala* c1,const Cheltuiala* c2) {
    return strcmp(get_tip(c1), get_tip(c2)) > 0;
}

int compara_tip_descrescator(const Cheltuiala* c1,const Cheltuiala* c2) {
    return strcmp(get_tip(c1), get_tip(c2)) < 0;
}


MyList* sorteaza_service(const ServiceCheltuieli* s, int criteriu, int ordine) {
    MyList* copie = createList();
    MyList* toate = get_all_service(s);

    for (int i = 0; i < size(toate); i++) {
        add(copie, get(toate, i));
    }

    FunctieComparare f = NULL;

    if (criteriu == 1)
        f = (ordine == 1) ? compara_suma_crescator : compara_suma_descrescator;
    else
        f = (ordine == 1) ? compara_tip_crescator : compara_tip_descrescator;

    for (int i = 0; i < size(copie) - 1; i++) {
        for (int j = i + 1; j < size(copie); j++) {
            Cheltuiala* c1 = (Cheltuiala*)get(copie, i);
            Cheltuiala* c2 = (Cheltuiala*)get(copie, j);

            if (f(c1, c2)) {
                set(copie, i, c2);
                set(copie, j, c1);
            }
        }
    }

    return copie;
}


MyList* filtrare_dupa_suma(const ServiceCheltuieli* s, float suma_limita) {
    MyList* rezultat = createList();
    MyList* toate = get_all_service(s);

    for (int i = 0; i < size(toate); i++) {
        Cheltuiala* c = (Cheltuiala*)get(toate, i);
        if (get_suma(c) <= suma_limita) {
            add(rezultat, c);
        }
    }

    return rezultat;
}

MyList* filtrare_dupa_zi(const ServiceCheltuieli* s, int zi) {
    MyList* rezultat = createList();
    MyList* toate = get_all_service(s);

    for (int i = 0; i < size(toate); i++) {
        Cheltuiala* c = (Cheltuiala*)get(toate, i);
        if (get_zi(c) == zi) {
            add(rezultat, c);
        }
    }

    return rezultat;
}

MyList* filtrare_dupa_tip(const ServiceCheltuieli* s,const char* tip) {
    MyList* rezultat = createList();
    MyList* toate = get_all_service(s);

    for (int i = 0; i < size(toate); i++) {
        Cheltuiala* c = (Cheltuiala*)get(toate, i);
        if (strcmp(get_tip(c), tip) == 0) {
            add(rezultat, c);
        }
    }

    return rezultat;
}

MyList* filtrare_interval_zile(const ServiceCheltuieli* s, int zi_start, int zi_final) {
    MyList* rezultat = createList();
    MyList* toate = get_all_service(s);

    for (int i = 0; i < size(toate); i++) {
        Cheltuiala* c = (Cheltuiala*)get(toate, i);
        if (get_zi(c) >= zi_start && get_zi(c) <= zi_final) {
            add(rezultat, c);
        }
    }

    return rezultat;
}


int sterge_dupa_zi(const ServiceCheltuieli* s, int zi)
{
    MyList* lista = get_all(s->repo);
    int ct_sterse = 0;

    salveazaUndo(s);

    int i = 0;
    while (i < size(lista)) {
        Cheltuiala* c = (Cheltuiala*)get(lista, i);

        if (get_zi(c) == zi) {
            sterge_cheltuiala_repo(s->repo, get_id(c));
            ct_sterse++;
        } else {
            i++;
        }
    }

    if (ct_sterse == 0) //nu s au gasit elemente
    {
        undo((ServiceCheltuieli*)s);
    }

    return ct_sterse;
}


void distruge_service(ServiceCheltuieli* s) {
    distruge_repo(s->repo);
    destroyList(s->undoList, (DestroyFunction)distruge_repo);
    free(s);
}