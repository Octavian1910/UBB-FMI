#include <stdio.h>


/*
Se citeste o propozitie de la tastatura. Sa se numere literele din fiecare cuvant si sa se afiseze aceste numere pe ecran.
*/

int nr_cuvinte(char sir[],int v[]);



int main()
{
    char sir[100];
    int v[100];
    fgets(sir,100,stdin);
    int len = nr_cuvinte(sir,v);
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d \n",v[i]);
    }
    
    
    return 0;
}
