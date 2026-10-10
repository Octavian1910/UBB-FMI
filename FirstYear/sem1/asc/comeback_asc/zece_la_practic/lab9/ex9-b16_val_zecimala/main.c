#include <stdio.h>

/*Se cere sa se citeasca de la tastatura un sir de numere, date in baza 16 (se citeste de la tastatura un sir de caractere si in memorie trebuie stocat un sir de numere). Sa se afiseze valoarea zecimala a nr atat ca numere fara semn cat si ca numere cu semn.
*/


void parsare(char sir[],int v[],int *len);
void afisare(int );  //nr cu semn si fara semn in b10  (%u si %d)


/*ffffff00 ffffff80 fffffffe ffffffff*/

int main()
{
   char sir[100];
   int v[100];
   int len = 0;
   fgets(sir,100,stdin);
   parsare(sir,v,&len);
   for(int i = 0 ; i < len ; i++)
   {
       //printf("%x ",v[i]);
       afisare(v[i]);
   }
   return 0;
}

void inutil()
{
    printf("");
}

