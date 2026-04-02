#include "teste.h"
#include "../domain/domain.h"
#include "../repository/repository.h"
#include "../service/service.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void teste_domain() {
    Cheltuiala* c = creeaza_cheltuiala(1, 23, 120, "mancare");
    assert(get_id(c) == 1);
    assert(get_zi(c) == 23);
    assert(get_suma(c) == 120);
    assert(strcmp(get_tip(c), "mancare") == 0);

    set_zi(c, 10);
    assert(get_zi(c) == 10);

    set_suma(c, 100);
    assert(get_suma(c) == 100);

    set_tip(c, "transport");
    assert(strcmp(get_tip(c), "transport") == 0);

    distruge_cheltuiala(c);
}

void teste_repository() {
    RepoCheltuieli* cheltuieli = creeaza_repo();

    adauga_repo(cheltuieli, creeaza_cheltuiala(1, 2, 30, "mancare"));
    adauga_repo(cheltuieli, creeaza_cheltuiala(2, 4, 50, "transport"));
    adauga_repo(cheltuieli, creeaza_cheltuiala(3, 5, 70, "imbracaminte"));

    assert(get_lungime_repo(cheltuieli) == 3);

    modifica_cheltuiala_repo(cheltuieli, creeaza_cheltuiala(1, 3, 35, "transport"));

    modifica_cheltuiala_repo(cheltuieli, creeaza_cheltuiala(100, 10, 200, "test"));

    Cheltuiala* c = (Cheltuiala*)get(cheltuieli->lista, 0);
    assert(get_zi(c) == 3);
    assert(get_suma(c) == 35);
    assert(strcmp(get_tip(c), "transport") == 0);

    sterge_cheltuiala_repo(cheltuieli, 1);


    Cheltuiala* c2 = (Cheltuiala*)get(cheltuieli->lista, 0);
    assert(get_id(c2) == 2);

    assert(sterge_cheltuiala_repo(cheltuieli, 10) == -1);


    distruge_repo(cheltuieli);
}

void teste_service() {
    RepoCheltuieli* r = creeaza_repo();
    ServiceCheltuieli* s = creeaza_service(r);

    adauga_service(s, 1, 2, 75, "mancare");
    adauga_service(s, 2, 4, 50, "transport");
    adauga_service(s, 3, 5, 70, "imbracaminte");

    assert(get_lungime_repo(r) == 3);

    assert(adauga_service(s, 1, 3, 60, "transport") == 1);
    assert(adauga_service(s, 4, 32, 400, "mancare") == 2);
    assert(adauga_service(s, 4, 0, 400, "mancare") == 2);
    assert(adauga_service(s, 5, 12, -5, "transport") == 3);

    sterge_cheltuiala_repo(r, 3);
    assert(get_lungime_repo(r) == 2);

    modifica_cheltuiala_service(s, 1, 3, 100, "transport");

    Cheltuiala* c = cauta_cheltuiala_service(s, 1);
    assert(get_zi(c) == 3);
    assert(get_suma(c) == 100);
    assert(strcmp(get_tip(c), "transport") == 0);

    assert(cauta_cheltuiala_service(s, 20) == NULL);

    assert(modifica_cheltuiala_service(s, 10, 3, 35, "transport") == 1);
    assert(modifica_cheltuiala_service(s, 2, 0, 35, "transport") == 2);
    assert(modifica_cheltuiala_service(s, 2, 34, 35, "transport") == 2);
    assert(modifica_cheltuiala_service(s, 2, 3, -4, "transport") == 3);



    MyList* dupa_suma1 = filtrare_dupa_suma(s, 50);
    assert(size(dupa_suma1) == 1);
    destroyList(dupa_suma1, NULL);

    MyList* dupa_suma2 = filtrare_dupa_suma(s, 5);
    assert(size(dupa_suma2) == 0);
    destroyList(dupa_suma2, NULL);

    MyList* dupa_zi1 = filtrare_dupa_zi(s, 3);
    assert(size(dupa_zi1) == 1);
    destroyList(dupa_zi1, NULL);

    MyList* dupa_zi2 = filtrare_dupa_zi(s, 15);
    assert(size(dupa_zi2) == 0);
    destroyList(dupa_zi2, NULL);

    MyList* dupa_tip1 = filtrare_dupa_tip(s, "transport");
    assert(size(dupa_tip1) == 2);
    assert(strcmp(get_tip((Cheltuiala*)get(dupa_tip1, 0)), "transport") == 0);
    destroyList(dupa_tip1, NULL);

    MyList* dupa_tip2 = filtrare_dupa_tip(s, "mancare");
    assert(size(dupa_tip2) == 0);
    destroyList(dupa_tip2, NULL);



    MyList* sortate1 = sorteaza_service(s, 1, 1);
    assert(get_id((Cheltuiala*)get(sortate1, 0)) == 2);
    assert(get_id((Cheltuiala*)get(sortate1, 1)) == 1);
    destroyList(sortate1, NULL);

    MyList* sortate2 = sorteaza_service(s, 1, 2);
    assert(get_id((Cheltuiala*)get(sortate2, 0)) == 1);
    destroyList(sortate2, NULL);

    adauga_service(s, 4, 10, 10, "altele");

    MyList* sortate3 = sorteaza_service(s, 2, 1);
    assert(strcmp(get_tip((Cheltuiala*)get(sortate3, 0)), "altele") == 0);
    destroyList(sortate3, NULL);

    MyList* sortate4 = sorteaza_service(s, 2, 2);
    assert(strcmp(get_tip((Cheltuiala*)get(sortate4, 0)), "transport") == 0);
    destroyList(sortate4, NULL);



    adauga_service(s, 4, 2, 75, "mancare");
    adauga_service(s, 5, 32, 75, "mancare");
    adauga_service(s, 6, 1, 75, "mancare");
    adauga_service(s, 7, 33, 75, "mancare");

    MyList* dupa_interval = filtrare_interval_zile(s, 2, 32);
    assert(size(dupa_interval) == 3);
    destroyList(dupa_interval, NULL);

    MyList* dupa_interval2 = filtrare_interval_zile(s, 40, 45);
    assert(size(dupa_interval2) == 0);
    destroyList(dupa_interval2, NULL);

    MyList* dupa_interval3 = filtrare_interval_zile(s, -3, -1);
    assert(size(dupa_interval3) == 0);
    destroyList(dupa_interval3, NULL);



    while (undo(s) == 0);
    assert(undo(s) == -1);

    // adaugare + undo
    adauga_service(s, 10, 1, 100, "test");
    assert(get_nr_cheltuieli(s) == 1);

    assert(undo(s) == 0);
    assert(get_nr_cheltuieli(s) == 0);

    // modificare + undo
    adauga_service(s, 20, 2, 200, "test2");
    modifica_cheltuiala_service(s, 20, 5, 300, "modificat");

    Cheltuiala* c_undo = cauta_cheltuiala_service(s, 20);
    assert(get_suma(c_undo) == 300);

    undo(s);

    c_undo = cauta_cheltuiala_service(s, 20);
    assert(get_suma(c_undo) == 200);

    // stergere + undo
    sterge_cheltuiala_service(s, 20);
    assert(sterge_cheltuiala_service(s, -1) == -1);

    assert(cauta_cheltuiala_service(s, 20) == NULL);

    undo(s);
    assert(cauta_cheltuiala_service(s, 20) != NULL);

    // undo multiplu
    adauga_service(s, 30, 3, 300, "multi");
    adauga_service(s, 40, 4, 400, "multi");

    assert(get_nr_cheltuieli(s) >= 3);

    undo(s);
    undo(s);

    assert(cauta_cheltuiala_service(s, 30) == NULL);
    assert(cauta_cheltuiala_service(s, 40) == NULL);


    while (undo(s) == 0);
    ElemType rez = removeLast(s->repo->lista);
    assert(undo(s) == -1);
    assert(rez == NULL);

    //functia noua de stergere

    adauga_service(s, 1, 2, 75, "mancare");
    adauga_service(s, 2, 2, 50, "transport");
    adauga_service(s, 3, 5, 70, "imbracaminte");

    int nr  = sterge_dupa_zi(s,2);
    assert(size(get_all_service(s)) == 1);
    assert(nr == 2);
    int nr2  = sterge_dupa_zi(s,2);
    assert(nr2 == 0);


    distruge_service(s);
}

void teste_ListedeListe() {
    RepoCheltuieli* repo = creeaza_repo();
    adauga_repo(repo, creeaza_cheltuiala(1,1,12,"factura"));
    adauga_repo(repo, creeaza_cheltuiala(2,2,10,"mancare"));

    MyList* undoList = createList();
    add(undoList, repo);
    assert(size(undoList) == 1);

    RepoCheltuieli* repo2 = creeaza_repo();
    add(undoList, repo2);
    assert(size(undoList) == 2);

    destroyList(undoList, (DestroyFunction)distruge_repo);
}