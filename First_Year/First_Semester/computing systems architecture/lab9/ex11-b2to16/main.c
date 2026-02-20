#include <stdio.h>

int baza2to16(char*,int*);
//;Se citeste de la tastatura un sir de mai multe numere in baza 2. Sa se afiseze aceste numere in baza 16.
int main()
{
    char sir[100];
    int v[100];
    fgets(sir,100,stdin);
    int len = baza2to16(sir,v);
    for (int i = 0 ; i < len ; i++)
    {
        printf("%x ",v[i]);
    }
    return 0;
    
}
