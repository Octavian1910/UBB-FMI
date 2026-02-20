#include <stdio.h>

/*
Se dau un sir care contine n reprezentari binare pe 8 biti date ca sir de caractere.
Sa se obtina un sir care contine numerele corespunzatoare reprezentarilor binare.
Exemplu:
Se da: '10100111b','01100011b','110b','101011b'
Se stocheaza: 10100111b, 01100011b, 110b, 101011b
*/

int parsare(char sir[],int v[]);

int main()
{
    char sir[100];
    int v[100];
    fgets(sir,100,stdin);
    int len = parsare(sir,v);
    for(int i = 0 ; i < len ; i++)
        printf("%d ",v[i]);

    return 0;
}


