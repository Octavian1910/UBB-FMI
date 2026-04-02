#include "domain.h"
#include <stdlib.h>
#include <string.h>

Cheltuiala* creeaza_cheltuiala(int id,int zi,float suma,char tip[]) {
    Cheltuiala* c=malloc(sizeof(Cheltuiala));
    c->id=id;
    c->zi=zi;
    c->suma=suma;
    c->tip=malloc(strlen(tip)+1);
    strcpy(c->tip,tip);
    return c;
}

int get_id(const Cheltuiala* c) {
    return c->id;
}
int get_zi(const Cheltuiala* c) {
    return c->zi;
}
float get_suma(const Cheltuiala* c) {
    return c->suma;
}
char* get_tip(const Cheltuiala* c) {
    return c->tip;
}



void set_zi(Cheltuiala* c,int zi) {
    c->zi=zi;
}
void set_suma(Cheltuiala* c,float suma) {
    c->suma=suma;
}
void set_tip(Cheltuiala* c,const char* tip) {
    free(c->tip);
    c->tip=malloc(strlen(tip)+1);
    strcpy(c->tip,tip);
}



void distruge_cheltuiala(ElemType c) {
    Cheltuiala* ch = (Cheltuiala*)c;
    free(ch->tip);
    free(ch);
}