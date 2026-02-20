#include <stdio.h>


/*
Sa se citeasca un sir de numere intregi s1 (reprezentate pe dublucuvinte) in baza 10. Sa se determine si sa se afiseze sirul s2 compus din cifrele aflate pe poziţia sutelor în fiecare numar intreg din sirul s1.
Exemplu:
Sirul s1: 5892, 456, 33, 7, 245
Sirul s2: 8, 4, 0, 0, 2
*/

int parsare(char sir[],int v[]);
int sute(int nr);

int main()
{
    char sir[150];
    int v[150];
    fgets(sir,100,stdin);
    int len = parsare(sir,v);
    printf("%d",len);
    printf("\n");
    for(int i = 0 ; i < len ; i++)
        printf("%d ",sute(v[i]));
    
   
    return 0;
}