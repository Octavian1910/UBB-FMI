#include <stdio.h>
#include <string.h>


/*
Se citeste de la tastatura un sir de numere in baza 10, cu semn. Sa se determine valoarea maxima din sir si sa se afiseze in fisierul max.txt (fisierul va fi creat) valoarea maxima, in baza 16.
*/

int val_max(int v[],int n);



int main()
{
    int v[100];
    int n = 0;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&v[i]);
    }
    printf("Val max este : %d",val_max(v,n));

    return 0;
}
