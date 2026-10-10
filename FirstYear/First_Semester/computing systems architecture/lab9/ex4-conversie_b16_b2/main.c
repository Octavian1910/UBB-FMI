/*Se da un sir de numere. Sa se afiseze valorile in baza 16 si in baza 2.
*/


#include <stdio.h>


char *baza2(int);
int parsare(char sir[],int v[]);

int main()
{
    char sir[100];
    int v[100];
    fgets(sir, 100, stdin);
    int len = parsare(sir,v);
    for(int i = 0 ;i < len ; i++)
    {
        printf("Baza 16 : %d = %x \n",v[i],v[i]);
        char *rezultat = baza2(v[i]);
        printf("Baza 2 : %s \n",rezultat);
    }
    return 0;
}

void inutil()
{
    printf("");
}

