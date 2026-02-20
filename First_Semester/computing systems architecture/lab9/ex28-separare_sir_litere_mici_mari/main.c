#include <stdio.h>
#include <string.h>


/*
Se citeste de la tastatura un sir de caractere (litere mici si litere mari, cifre, caractere speciale, etc). Sa se formeze un sir nou doar cu literele mici si un sir nou doar cu literele mari. Sa se afiseze cele 2 siruri rezultate pe ecran.
*/

void litere_mici(char sir[],char rez[]);
void litere_mari(char sir[],char rez[]);



int main()
{
    char sir[100];
    char sir1[100];
    char sir2[100];
    fgets(sir,100,stdin);
    
    
    litere_mici(sir,sir1);
    
    
    printf("Sir cu caractere mici : %s \n",sir1);
    
    litere_mari(sir,sir2);
    
    printf("\nSir cu caractere mari :  %s",sir2);
    
    
    return 0;
}
