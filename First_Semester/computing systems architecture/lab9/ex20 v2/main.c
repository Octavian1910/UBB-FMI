#include <stdio.h>

/*
Se citeste din fisierul numere.txt un sir de numere. Sa se determine sirul destinatie D care contine numerele din sirul initial cu valorile dublate dar in ordine inversa din sirul initial. Sa se afiseze sirul obtinut pe ecran.
Ex: s: 12, 2, 4, 5, 0, 7 => 14, 0, 10, 8, 4, 24
*/


int parsare(char sir[],int v[]);
void intoarce_si_dubleaza(int v1[],int v2[],int len);

int main()
{
    char sir1[100];
    int v[100];
    int rez[100];
    fgets(sir1,100,stdin);
    
    int len = parsare(sir1,v);
    
    intoarce_si_dubleaza(v,rez,len);
    for(int i = 0 ; i < len ; i++)
    {
        printf("%d ",rez[i]);
    }
    
    //printf("%d",len);
    
    return 0;
}


