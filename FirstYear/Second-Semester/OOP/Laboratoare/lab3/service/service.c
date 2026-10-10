#include "service.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
ServiceFarmacie* creeaza_service_farmacie(RepoFarmacie *Repo,ValidatorMedicament* Validator)
{
    ServiceFarmacie* s = malloc(sizeof(ServiceFarmacie));
    s->repo = Repo;
    s->validator = Validator;
    return s;
}

Medicament* cauta_medicament_service(const ServiceFarmacie* s,int cod)
{
    return cauta_medicament_repo(s->repo,cod);
}

void distruge_service_farmacie(ServiceFarmacie *s)
{
    distrugeRepo(s->repo);
    free(s);
}

int nr_medicamente_service(const ServiceFarmacie *s)
{
    return nr_medicamente_repo(s->repo);
}

int adaugaService(const ServiceFarmacie* s,int cod,char* nume,int concentratie,int cantitate)
{
    Medicament *medicament = creeazaMedicament(cod,nume,concentratie,cantitate);
    int erori = valideazaMedicament(medicament);
    if (erori)
    {
        distrugeMedicament(medicament);
        return erori;
    }
    adauga_repo(s->repo,medicament);
    return 0;
}

int actualizeazaService(const ServiceFarmacie *s,int cod,char* nume,int concentratie)
{
    Medicament* m = creeazaMedicament(cod,nume,concentratie,1);
    int erori = valideazaMedicament(m);
    if (erori == 0)
    {
        return actualizeaza_element_repo(s->repo,m);
    }
    else
    {
        distrugeMedicament(m);
        return erori;
    }
}

Medicament** get_all_service(const ServiceFarmacie* s)
{
    return get_all_repo(s->repo);
}

int sterge_service(const ServiceFarmacie* s,int cod)
{
    return sterge_repo(s->repo,cod);
}


// Comparare dupa nume (crescator)
int comparaNume(Medicament* m1, Medicament* m2) {
    int rez = strcmp(get_nume(m1), get_nume(m2));
    if (rez == 0) {
        return get_cantitate(m1) - get_cantitate(m2);
    }
    return rez;
}

// Comparare dupa cantitate (crescator)
int comparaCantitate(Medicament* m1, Medicament* m2) {
    if (get_cantitate(m1) > get_cantitate(m2)) return 1;
    if (get_cantitate(m1) < get_cantitate(m2)) return -1;
    return 0;
}


Medicament** sortareMedicamente(const ServiceFarmacie* s, FunctieComparare cmp, int ordine, int *lungime) {
    int nr = nr_medicamente_service(s);
    *lungime = nr;
    Medicament** lista = get_all_service(s);

    for (int i = 0; i < nr - 1; ++i) {
        for (int j = i + 1; j < nr; ++j) {
            int rez = cmp(lista[i], lista[j]);

            int trebuie_schimbat = 0;
            if (ordine == 1 && rez > 0) trebuie_schimbat = 1;      // Crescator
            if (ordine == 0 && rez < 0) trebuie_schimbat = 1;      // Descrescator

            if (trebuie_schimbat) {
                Medicament *aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    return lista;
}

int convertStringToInt(const char* val)
{
    int nr = 0;
    for (int i = 0 ; i < (int)strlen(val) ; ++i)
    {
        int uc = val[i] - '0';
        nr = (nr*10) + uc;
    }
    return nr;
}

Medicament** filtrareMedicamente(const ServiceFarmacie* s,int criteriu,const char* valoare,int* lungime)
{

    int nr = nr_medicamente_service(s);
    int ct = 0;

    Medicament** lista = get_all_service(s);

    Medicament** rezultat = malloc(sizeof(Medicament*) * nr);

    if (criteriu == 1)
    {
        int val = convertStringToInt(valoare);

        for (int i = 0 ; i < nr ; ++i)
        {
            if (get_cantitate(lista[i]) < val)
            {
                rezultat[ct++] = lista[i];
            }
        }
    }
    else
    {
        for (int i = 0 ; i < nr ; ++i)
        {
            char* nume = get_nume(lista[i]);
            if ( toupper(nume[0]) == toupper(valoare[0]))
            {
                rezultat[ct++] = lista[i];
            }
        }
    }
    *lungime = ct;
    return rezultat;
}

//sas alexia maria