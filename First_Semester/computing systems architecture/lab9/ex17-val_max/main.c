#include <stdio.h>

/*
Se citeste de la tastatura un sir de numere in baza 10 fara semn. Sa se determine valoarea minima din sir si sa se afiseze in fisierul min.txt (fisierul va fi creat) valoarea minima, in baza 16
*/

int parsare(char sir[],int v[]);
int val_maxima(int v[],int len);

int main()
{
    char sir[100];
    int v[100];
    fgets(sir,100,stdin);
    int len = parsare(sir,v);
    for(int i = 0 ; i < len ; i++)
        printf("%d ",v[i]);
    
    int nr_minim = val_minima(v,len);
    printf("\nNr maxim este : %d ",nr_minim);
    

    return 0;
}


