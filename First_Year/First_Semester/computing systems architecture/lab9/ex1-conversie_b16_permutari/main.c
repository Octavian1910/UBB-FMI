#include <stdio.h>
//da un numar a reprezentat pe 32 biti fara semn. Se cere sa se afiseze reprezentarea in baza 16 a lui a, precum
//si rezultatul permutarilor circulare ale cifrelor 

int creeare_numar(char sir[]);
void permutari(int);


int main()
{
    char sir[100];
    scanf("%s",sir);
    int numar = creeare_numar(sir);
    printf("%x \n",numar);
    permutari(numar);
    
    
    
    return 0;
}