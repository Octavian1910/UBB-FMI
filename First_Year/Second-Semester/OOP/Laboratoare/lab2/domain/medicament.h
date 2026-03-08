#ifndef MEDICAMENT_H_
#define MEDICAMENT_H_

typedef struct
{
    int cod;
    char* nume;
    int concentratie;
    int cantitate;
}Medicament;

Medicament* creeazaMedicament(int cod,char* nume,int concentratie,int cantitate);

void distrugeMedicament(Medicament* m);

//gettere
int get_cod(Medicament* m);
int get_concentratie(Medicament* m);
int get_cantitate(Medicament* m);
char* get_nume(Medicament* m);

//settere
void set_cod(Medicament* m,int cod_nou);
void set_concentratie(Medicament* m,int concentratie_noua);
void set_cantitate(Medicament* m,int cantitate_noua);
void set_nume(Medicament* m,char* nume_nou);

#endif