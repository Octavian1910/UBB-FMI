#include "service.h"
#include <stdlib.h>
#include <string.h>

ServiceFarmacie* creeaza_service_farmacie(RepoFarmacie *Repo,ValidatorMedicament* Validator)
{
    ServiceFarmacie* s = malloc(sizeof(ServiceFarmacie));
    s->repo = Repo;
    s->validator = Validator;
    return s;
}

Medicament* cauta_medicament_service(ServiceFarmacie* s,int cod)
{
    return cauta_medicament_repo(s->repo,cod);
}

void distruge_service_farmacie(ServiceFarmacie *s)
{
    distrugeRepo(s->repo);
    free(s);
}

int nr_medicamente_service(ServiceFarmacie *s)
{
    return nr_medicamente_repo(s->repo);
}

int adaugaService(ServiceFarmacie* s,int cod,char* nume,int concentratie,int cantitate)
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

int actualizeazaService(ServiceFarmacie *s,int cod,char* nume,int concentratie)
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

Medicament** get_all_service(ServiceFarmacie* s)
{
    return get_all_repo(s->repo);
}

int sterge_service(ServiceFarmacie* s,int cod)
{
    return sterge_repo(s->repo,cod);
}


int compara(Medicament* m1,Medicament* m2,int criteriu)
{
    if (criteriu == 1) //sortare dupa nume
    {
        int rez = strcmp(get_nume(m1),get_nume(m2));
        if (rez != 0)
        {
            return rez;
        }
        else
        {
            return get_cantitate(m1) - get_cantitate(m2);
        }
    }
    else
    {
        return get_cantitate(m1) - get_cantitate(m2);
    }


}


Medicament** sortareMedicamente(ServiceFarmacie* s,int criteriu,int crescator,int *lungime)
{

    *lungime = nr_medicamente_service(s);
    int nr = nr_medicamente_service(s);

    Medicament** lista = get_all_service(s);

    for (int i = 0 ; i < nr - 1 ; ++i)
        for (int j = i + 1 ; j < nr ; ++j)
        {

            int rezultat_comparatie = compara(lista[i],lista[j],criteriu);


            //cazurile cand trb schimbat
            int trb_schimbat = 0;
            if (crescator &&  rezultat_comparatie > 0 ) trb_schimbat = 1;
            if (!crescator &&  rezultat_comparatie < 0 ) trb_schimbat = 1;
            if (trb_schimbat)
            {
                Medicament *aux = lista[i];
                lista[i] = lista[j];
                lista[j] =  aux;
            }
        }
    return lista;
}

int convertStringToInt(char* val)
{
    int nr = 0;
    for (int i = 0 ; i < strlen(val) ; ++i)
    {
        int uc = val[i] - '0';
        nr = (nr*10) + uc;
    }
    return nr;
}

Medicament** filtrareMedicamente(ServiceFarmacie* s,int criteriu,char* valoare,int* lungime)
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
            if ( nume[0] == valoare[0] || nume[0] == valoare[0] + 32 || nume[0] == valoare[0] - 32 )
            {
                rezultat[ct++] = lista[i];
            }
        }
    }
    *lungime = ct;
    return rezultat;
}

