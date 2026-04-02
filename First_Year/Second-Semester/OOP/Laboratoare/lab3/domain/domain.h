#ifndef CHELTUIALA_H
#define CHELTUIALA_H

typedef struct {
    int id;
    int zi;
    float suma;
    char* tip;
} Cheltuiala;

typedef void* ElemType;

/*
 * Creeaza o noua cheltuiala
 * :param id: identificator unic (int)
 * :param zi: ziua cheltuielii (int)
 * :param suma: suma cheltuielii (float)
 * :param tip: tipul cheltuielii (char*)
 * :return: pointer la obiect Cheltuiala alocat dinamic
 */
Cheltuiala* creeaza_cheltuiala(int id, int zi, float suma, char* tip);

/*
 * Returneaza id-ul unei cheltuieli
 * :param c: pointer la Cheltuiala
 * :return: id (int)
 */
int get_id(const Cheltuiala* c);

/*
 * Returneaza ziua unei cheltuieli
 * :param c: pointer la Cheltuiala
 * :return: zi (int)
 */
int get_zi(const Cheltuiala* c);

/*
 * Returneaza suma unei cheltuieli
 * :param c: pointer la Cheltuiala
 * :return: suma (float)
 */
float get_suma(const Cheltuiala* c);

/*
 * Returneaza tipul unei cheltuieli
 * :param c: pointer la Cheltuiala
 * :return: tip (char*)
 */
char* get_tip(const Cheltuiala* c);

/*
 * Modifica ziua unei cheltuieli
 * :param c: pointer la Cheltuiala
 * :param zi: noua zi (int)
 */
void set_zi(Cheltuiala* c, int zi);

/*
 * Modifica suma unei cheltuieli
 * :param c: pointer la Cheltuiala
 * :param suma: noua suma (float)
 */
void set_suma(Cheltuiala* c, float suma);

/*
 * Modifica tipul unei cheltuieli
 * :param c: pointer la Cheltuiala
 * :param tip: noul tip (char*)
 */
void set_tip(Cheltuiala* c, const char* tip);

/*
 * Elibereaza memoria ocupata de o cheltuiala
 * :param c: pointer la elementul de tip Cheltuiala ce trebuie distrus
 */
void distruge_cheltuiala(ElemType c);

#endif