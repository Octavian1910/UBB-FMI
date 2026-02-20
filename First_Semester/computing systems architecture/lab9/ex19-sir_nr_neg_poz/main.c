#include <stdio.h>

/*
Se citesc din fisierul numere.txt mai multe numere (pozitive si negative). Sa se creeze 2 siruri rezultat N si P astfel: N - doar numere negative si P - doar numere pozitive. Afisati cele 2 siruri rezultate pe ecran.
*/

int parsare(char sir[],int v[]);
int pozitive(int v[],int rez[],int len);
int negative(int v[],int rez[],int len);


int main()
{
    char sir[100];
    int v[100];
    fgets(sir,100,stdin);
    int len = parsare(sir,v);
    for(int i = 0 ; i < len ; i++)
        printf("%d ",v[i]);
    
    printf("\nNr pozitive\n");
    int rez1[100];
    int len2 = pozitive(v,rez1,len);
    for(int i = 0 ; i < len2 ; i++)
        printf("%d ",rez1[i]);
    
    printf("\n Nr negative \n");
    int rez2[100];
    int len3 = negative(v,rez2,len);
    for(int i = 0 ; i < len3 ; i++)
        printf("%d ",rez2[i]);


    return 0;
}


