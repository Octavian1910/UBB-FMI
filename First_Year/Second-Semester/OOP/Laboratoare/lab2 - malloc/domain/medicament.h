#ifndef MEDICAMENT_H_
#define MEDICAMENT_H_

/*
 Constructor MEDICAMENT
*/
typedef struct
{
    int cod;
    char* nume;
    int concentratie;
    int cantitate;
} Medicament;


/*
 Functia creeaza un medicament

 :param cod: codul medicamentului
 :param nume: numele medicamentului
 :param concentratie: concentratia medicamentului
 :param cantitate: cantitatea din stoc

 :return: pointer la obiect de tip Medicament alocat dinamic

 :pre:
 cod > 0
 nume != NULL
 strlen(nume) > 0
 concentratie > 0
 cantitate >= 0

 :post:
 se aloca memorie pentru un obiect Medicament
*/
Medicament* creeazaMedicament(int cod,char* nume,int concentratie,int cantitate);


/*
 Functia distruge un medicament si elibereaza memoria

 :param m: pointer la medicament

 :pre:
 m != NULL

 :post:
 memoria ocupata de medicament este eliberata
*/
void distrugeMedicament(Medicament* m);


/*
 Functia returneaza codul medicamentului

 :param m: pointer la medicament
 :return: codul medicamentului

 :pre:
 m != NULL

 :post:
 se returneaza codul medicamentului
*/
int get_cod(Medicament* m);


/*
 Functia returneaza concentratia medicamentului

 :param m: pointer la medicament
 :return: concentratia medicamentului

 :pre:
 m != NULL

 :post:
 se returneaza concentratia medicamentului
*/
int get_concentratie(Medicament* m);


/*
 Functia returneaza cantitatea medicamentului

 :param m: pointer la medicament
 :return: cantitatea medicamentului

 :pre:
 m != NULL

 :post:
 se returneaza cantitatea medicamentului
*/
int get_cantitate(Medicament* m);


/*
 Functia returneaza numele medicamentului

 :param m: pointer la medicament
 :return: numele medicamentului

 :pre:
 m != NULL

 :post:
 se returneaza numele medicamentului
*/
char* get_nume(Medicament* m);


/*
 Functia modifica codul medicamentului

 :param m: pointer la medicament
 :param cod_nou: noul cod

 :pre:
 m != NULL
 cod_nou > 0

 :post:
 codul medicamentului este actualizat
*/
void set_cod(Medicament* m,int cod_nou);


/*
 Functia modifica concentratia medicamentului

 :param m: pointer la medicament
 :param concentratie_noua: noua concentratie

 :pre:
 m != NULL
 concentratie_noua > 0

 :post:
 concentratia medicamentului este actualizata
*/
void set_concentratie(Medicament* m,int concentratie_noua);


/*
 Functia modifica cantitatea medicamentului

 :param m: pointer la medicament
 :param cantitate_noua: noua cantitate

 :pre:
 m != NULL
 cantitate_noua >= 0

 :post:
 cantitatea medicamentului este actualizata
*/
void set_cantitate(Medicament* m,int cantitate_noua);


/*
 Functia modifica numele medicamentului

 :param m: pointer la medicament
 :param nume_nou: noul nume

 :pre:
 m != NULL
 nume_nou != NULL
 strlen(nume_nou) > 0

 :post:
 numele medicamentului este actualizat
*/
void set_nume(Medicament* m,char* nume_nou);


#endif