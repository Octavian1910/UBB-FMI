#include <stdio.h>
#include <string.h>

/*
Se dau trei siruri de caractere. Sa se afiseze cel mai lung sufix comun pentru fiecare din cele trei perechi de cate doua siruri ce se pot forma.
*/

char *sufix(char sir1[],char sir2[]);

int main()
{
    char sir1[] = "andreivacariu";
    char sir2[] = "asdqwdq3acariu";
    char sir3[] = "riu";
    
    printf("%s\n",sufix(sir1,sir2));
    printf("%s\n",sufix(sir1,sir3));
    printf("%s\n",sufix(sir2,sir3));
    
    return 0;
}

