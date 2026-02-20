#include <stdio.h>


//Se citesc mai multe numere de la tastatura, in baza 2. Sa se afiseze aceste numere in baza 8.

int salvare(char sir[],int v[]);
void conversie_baza_8(int n);

int main()
{
    char sir[100];
    int v[100];
    
    fgets(sir,100,stdin);
    
    int len = salvare(sir,v);
    for(int i = 0 ; i < len ; i++)
    {
      conversie_baza_8(v[i]);
        printf("\n");  
    }
        
    return 0;
}

void inutil()
{
    printf("");
}

