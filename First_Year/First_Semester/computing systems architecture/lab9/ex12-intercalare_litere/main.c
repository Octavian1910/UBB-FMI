#include <stdio.h>
#include <string.h>

/*
Se dau doua siruri de caractere de lungimi egale. Se cere sa se calculeze si sa se afiseze rezultatele intercalarii literelor, pentru cele doua intercalari posibile (literele din primul sir pe pozitii pare, respectiv literele din primul sir pe pozitii impare).
*/

void intercalare(char sir1[],char sir2[],char rez[]);

int main()
{
    char sir1[] = "OsaLuam10laPractic";
    char sir2[] = "Propozitiademaisus";
    char sir3[150];
    
    intercalare(sir1,sir2,sir3);
    printf("%s",sir3);
    
    intercalare(sir2,sir1,sir3);
    printf("\n%s",sir3);
    
    return 0;
}

