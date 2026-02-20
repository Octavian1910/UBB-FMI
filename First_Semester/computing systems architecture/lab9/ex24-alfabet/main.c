#include <stdio.h>
#include <string.h>


/*
Sa se citeasca un sir s1 (care contine doar litere mici). Folosind un alfabet (definit in segmentul de date), determinati si afisati sirul s2 obtinut prin substituirea fiecarei litere a sirului s1 cu litera corespunzatoare din alfabetul dat.
Exemplu:
Alfabetul: OPQRSTUVWXYZABCDEFGHIJKLMN
Sirul s1:  anaaremere
Sirul s2:  OBOOFSASFS
*/

void inlocuire(char sir1[],char sir2[],char sir3[]);



int main()
{
    char alfabet[] = "OPQRSTUVWXYZABCDEFGHIJKLMN";
    char sir1[100];
    char sir2[100];
    fgets(sir1,100,stdin);
    
    
    inlocuire(alfabet,sir1,sir2);
    
    
    printf("%s",sir2);

    
    
    return 0;
}
