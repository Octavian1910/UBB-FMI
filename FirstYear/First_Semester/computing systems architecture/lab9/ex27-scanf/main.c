#include <stdio.h>

/*
Se citesc din fisierul numere.txt mai multe numere (pare si impare). Sa se creeze 2 siruri rezultat N si P astfel: N - doar numere impare si P - doar numere pare. Afisati cele 2 siruri rezultate pe ecran.
*/


int pare(int v[],int rez[],int n);
int impare(int v[],int rez[],int n);




int main()
{
    int n;
    scanf("%d", &n);  

    int v[150];
    int p[150];
    int ip[150];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);   // citește fiecare număr
    }

     printf("\n Nr pare :");
    int len = pare(v,p,n);
    
    for(int i = 0; i < len; i++)
    {
        printf("%d ",p[i]);
    }
    
    printf("\n Nr impare :");
    int len2 = impare(v,ip,n);
    for(int i = 0; i < len2; i++)
    {
        printf("%d ",ip[i]);
    }
    
    return 0;
}
