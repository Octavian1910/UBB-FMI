
#include <stdio.h>

/*
Fie programul main.c in care se citeste de la tastatura un caracter x si un numar natural n(n < 20). Apoi se citesc n cuvinte de lungime maxima de 30 caractere fiecare.

Pentru fiecare cuvant, se vor face urmatoarele operatii:
Daca cuvantul nu contine caracterul x, acesta nu se va afisa.
Daca cuvantul contine caracterul x si are un numar par de caractere, se va afisa.
Daca cuvantul contine caracterul x si are un numar impar de caractere, se va afisa oglinditul cuvantului.
In modul1.asm se va defini procedura OGLINDIT care va determina oglinditul cuvantului daca are un numar impar de caractere. In caz contrar cuvantul ramane neschimbat.

In modul2.asm se va defini procedura VERIFICA care primeste ca si parametrii un sir de caractere si un caracter si va returna 1 daca apare caracterul in sirul de caractere si 0 in caz contrar.

Exemplu:
input:
a
3
mere
magenta
astazi

output:
atnegam
astazi
*/

int VERIFICA(char sir[],char x);
void OGLINDIT(char sir[]);

int main()
{
    char x;
    scanf("%c",&x);
    
    int n;
    scanf("%d",&n);
    
    char sir[32];
    fgets(sir,32,stdin); 
    for(int i = 0 ; i < n ; i++)
    {
       
        fgets(sir,32,stdin);
        if(VERIFICA(sir,x) == 1)
        {
                OGLINDIT(sir);
                printf("\n");
        } 
    }
    
    return 0;
}

void inutil()
{
    printf("");
}

