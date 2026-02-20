#include <stdio.h>

/*
Se citeste o propozitie de la tastatura. Sa se inverseze fiecare cuvant si sa se afiseze pe ecran.
*/

void afisare_inversa(char sir[],char rez[]);



int main()
{
    char sir[100];
    char rez[100];
  
    fgets(sir,100,stdin);

    afisare_inversa(sir,rez);
    
    printf("%s",rez);
    
    return 0;
}

void inutil()
{
    printf("");
    
}
