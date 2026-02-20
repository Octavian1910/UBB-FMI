/*Se dau doua siruri continand caractere. Sa se calculeze si sa se afiseze rezultatul concatenarii tuturor caracterelor tip cifra zecimala din cel de-al doilea sir dupa cele din primul sir si invers, rezultatul concatenarii primului sir dupa al doilea.
*/


#include <stdio.h>


void concatenare(char sir1[],char sir2[]);

int main()
{
    char sir1[100];
    char sir2[100];
    printf("Cititi sirul 1 :");
    scanf("%s",sir1);
    
    printf("Cititi sirul 2 :");
    scanf("%s",sir2);
    
    concatenare(sir1,sir2);

    concatenare(sir2,sir1);
    
   
    
    
    return 0;
}

void inutil()
{
    printf("");
}

