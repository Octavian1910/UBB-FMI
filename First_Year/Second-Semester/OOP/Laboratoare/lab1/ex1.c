#include <stdio.h>
#include <stdlib.h>

/*
    Meniu pentru afisarea cerintelor
 */
void meniu()
{
    printf("Meniu \n");
    printf("1)Genereare nr prime mai mici decat un numar dat \n");
    printf("2)Genereaza primele n numere prime \n");
    printf("3)Iesire \n");
}


int e_prim(int numar)
{
    /*Functia primeste un numar si verifica daca acesta este prim
    *:param n: un numar nat mai mare decat 0
    *:returns: 1 daca el este prim , 0 altfel
    *pre : numar este un nr >= 0
    *post : 0 daca nu e prim , 1 daca e prim
    */
    if (numar < 2)
        return 0;
    if (numar == 2)
        return 1;
    if (numar % 2 == 0)
        return 0;
    for (int i = 3; i * i <= numar; i += 2)
        if (numar % i == 0)
            return 0;
    return 1;

}


int genereaza_nr_prime_mai_mici_decat_un_nr_dat(int numar,int *rezultat)
{
    /*Functia genereaza numerele mai mici decat numarul dat
    *:param numar: numar este de tip int si este mai mare decat 0
    *:param vector: initial nul , se pun nr mai mici decat nr dat
    *:returns: un nr reprezenant nr de numere mai mici decat nr dat
    *pre : numar >= 0 este numar natural ,iar  rezultat este un vector nul
    *post: intoarce dimensiune vectorului care contine nr de nr prime dorit
    */
    int dim = 0;
    if (numar <= 1)  //daca nr este negativ
        return 0;

    for (int i = 2; i < numar; ++i)
    {
        if (e_prim(i))
        {
            rezultat[dim++] = i;
        }
    }
    return dim;
}


void afiseaza_rezultat(const int *rezultat,int dimensiune)
{
    /*Functie care afiseaza un vector
    *:param rezultat: vectorul
    *:dimensiune: un int >= 0
    *:returns: -
    *pre: dimensiune >= 0
    *post : afiseaza pe ecran elementele din rezultat
    */
    if (dimensiune <= 0)
    {
        printf("Nu exista numere prime mai mici decat numarul dat! \n");
    }
    else
    {
        for (int i = 0 ; i < dimensiune ; ++i)
        {
            printf("%d ",rezultat[i]);
        }
        printf("\n");
    }
}

void primele_n_numere_prime(int n,int *rezultat)
{
    /*Functia genereaza primele n numere prime
     * :param n: un int
     * :param rezultat: un vector nul
     * :pre: n este un nr , iar rezultat este un vector gol cu memorie suficienta
     * :post: in rezultat se vor afla primele n numere cerute
      */
    int ct = 0,i = 2;
    while (ct < n)
    {
        if (e_prim(i) == 1)
        {
            rezultat[ct++] = i;
        }
        i++;
    }
}

int main() {

    while (1)
    {
        meniu();
        int comanda = 0;
        scanf("%d",&comanda);
        switch (comanda) //Genereare nr prime mai mici decat un numar dat
        {
            case(1):
            {
                int nr = 0;
                printf("Da numar : ");
                scanf("%d",&nr);
                int rezultat[100];
                int dimensiune = genereaza_nr_prime_mai_mici_decat_un_nr_dat(nr,rezultat);
                afiseaza_rezultat(rezultat,dimensiune);
                break;
            }
            case(2):
            {
                int n = 0;
                printf("Introdu n : ");
                scanf("%d",&n);
                int* rezultat = malloc(n * sizeof(*rezultat));
                primele_n_numere_prime(n,rezultat);
                printf("Primele %d numere prime sunt : " , n);
                afiseaza_rezultat(rezultat,n);
                free(rezultat);
                break;
            }
            case(3):
            {
                return 0;
            }
            default:
            {
                printf("Comanda nu este buna!");
            }
        }

    }
}