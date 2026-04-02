#include "repository.h"
#include <stdlib.h>

// creare repo
RepoCheltuieli* creeaza_repo() {
    RepoCheltuieli* repo = malloc(sizeof(RepoCheltuieli));
    repo->lista = createList();
    return repo;
}

// adaugare
void adauga_repo(const RepoCheltuieli* repo, ElemType el) {
    add(repo->lista, el);
}

// cautare
ElemType cauta_cheltuiala_repo(const RepoCheltuieli* repo, int id) {
    for (int i = 0; i < size(repo->lista); i++) {
        Cheltuiala* c = get(repo->lista, i);
        if (get_id(c) == id) {
            return c;
        }
    }
    return NULL;
}

// modificare
void modifica_cheltuiala_repo(const RepoCheltuieli* repo, ElemType el_nou) {
    for (int i = 0; i < size(repo->lista); i++) {
        Cheltuiala* c = get(repo->lista, i);
        if (get_id(c) == get_id(el_nou)) {
            distruge_cheltuiala(c);
            set(repo->lista, i, el_nou);
            return;
        }
    }
}

// stergere
int sterge_cheltuiala_repo(const RepoCheltuieli* repo, int id) {
    for (int i = 0; i < size(repo->lista); i++) {
        Cheltuiala* c = get(repo->lista, i);
        if (get_id(c) == id) {
            distruge_cheltuiala(c);
            removeAt(repo->lista, i);
            return 0;
        }
    }
    return -1;
}

// lungime
int get_lungime_repo(const RepoCheltuieli* repo) {
    return size(repo->lista);
}

MyList* get_all(const RepoCheltuieli* repo) {
    return repo->lista;
}


ElemType copyCheltuiala(ElemType c) {
    Cheltuiala* ch = (Cheltuiala*)c;
    return creeaza_cheltuiala(
        get_id(ch),
        get_zi(ch),
        get_suma(ch),
        get_tip(ch)
    );
}

RepoCheltuieli* copiaza_repo(const RepoCheltuieli* repo) {
    RepoCheltuieli* copie = malloc(sizeof(RepoCheltuieli));
    copie->lista = deepCopyList(repo->lista, copyCheltuiala);
    return copie;
}


// distrugere
void distruge_repo(RepoCheltuieli* repo) {
    destroyList(repo->lista, distruge_cheltuiala);
    free(repo);
}