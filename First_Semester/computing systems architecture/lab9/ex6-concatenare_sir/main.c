//Se citesc trei siruri de caractere. Sa se determine si sa se afiseze rezultatul concatenarii lor.
///Sa se converteascsa literele mici in mari

#include <stdio.h>

char* concatenare(char*,char*);

int main()
{
    char sir1[100],sir2[100],sir3[100];
    

    fgets(sir1,100,stdin);
    fgets(sir2,100,stdin);
    fgets(sir3,100,stdin);

    char *rez = concatenare(sir1,sir2);
    char *rez2 = concatenare(rez,sir3);
    
    printf("Sirul concatenat este : %s",rez2);
    return 0;
    
    
}