#include <stdio.h>

int conversie(char*, int*);

int main()
{
    char sir[100];
    int v[100];


    fgets(sir, 100, stdin);  

    int len = conversie(sir, v);  

    printf("Sunt %d numere:\n", len);
    for (int i = 0; i < len; i++)
        printf("%d ", v[i]);

    printf("\n");
    return 0;
}
