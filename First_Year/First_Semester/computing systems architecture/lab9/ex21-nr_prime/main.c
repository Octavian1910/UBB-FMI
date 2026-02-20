#include <stdio.h>


/*
Se citeste de la tastatura un sir de numere in baza 10. Sa se afiseze numerele prime.
*/

int parsare(char sir[],int v[]);
int e_nr_prim(int nr);



int main()
{
    char sir[100];
    int v[100];
    fgets(sir,100,stdin);
    int len = parsare(sir,v);
    
    printf("%d \n",len);

    for(int i = 0 ; i < len ; i++)
    {
        if(e_nr_prim(v[i]))
          printf("%d ",v[i]);
    }

    
    
    return 0;
}
