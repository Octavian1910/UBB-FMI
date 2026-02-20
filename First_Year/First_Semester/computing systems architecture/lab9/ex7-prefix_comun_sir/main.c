//Se dau trei siruri de caractere. Sa se afiseze cel mai lung prefix comun pentru fiecare din cele trei //perechi de cate doua siruri ce se pot forma.

#include <stdio.h>

char* prefix(char*,char*);

int main()
{
    char sir1[100],sir2[100],sir3[100];
    

    scanf("%s %s %s",sir1,sir2,sir3);

    
    printf("%s\n",prefix(sir1,sir2));
    printf("%s\n",prefix(sir1,sir3));
    printf("%s\n",prefix(sir2,sir3));
    
    return 0;
    
    
}