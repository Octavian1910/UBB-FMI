#include "MyList.h"
#include <stdlib.h>

#define capacitate 2

MyList* createList() {
    MyList* l = malloc(sizeof(MyList));
    l->size = 0;
    l->capacity = capacitate;
    l->elems = malloc(sizeof(ElemType) * l->capacity);
    return l;
}

static void resize(MyList* l) {
    int newCapacity = l->capacity * 2;

    ElemType* newElems = malloc(sizeof(ElemType) * newCapacity);

    for (int i = 0; i < l->size; i++) {
        newElems[i] = l->elems[i];
    }

    free(l->elems);

    l->elems = newElems;
    l->capacity = newCapacity;
}

void add(MyList* l, ElemType el) {
    if (l->size == l->capacity) {
        resize(l);
    }
    l->elems[l->size++] = el;
}

ElemType get(const MyList* l, int poz) {
    return l->elems[poz];
}

void set(const MyList* l, int poz, ElemType el) {
    l->elems[poz] = el;
}

int size(const MyList* l) {
    return l->size;
}

void removeAt(MyList* l, int poz) {
    for (int i = poz; i < l->size - 1; i++) {
        l->elems[i] = l->elems[i + 1];
    }
    l->size--;
}

ElemType removeLast(MyList* l) {
    if (l->size == 0) return NULL;
    l->size--;
    return l->elems[l->size];
}

void destroyList(MyList* l, DestroyFunction destroyElem) {
    if (destroyElem != NULL) {
        for (int i = 0; i < l->size; i++) {
            destroyElem(l->elems[i]);
        }
    }
    free(l->elems);
    free(l);
}

MyList* deepCopyList(const MyList* l, CopyFunction copyElem) {
    MyList* copie = createList();
    for (int i = 0; i < l->size; i++) {
        ElemType elNou = copyElem(l->elems[i]);
        add(copie, elNou);
    }
    return copie;
}