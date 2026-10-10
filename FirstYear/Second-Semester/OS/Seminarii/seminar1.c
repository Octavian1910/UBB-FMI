#include <stdlib.h>
//alocare statica
char sir[100];
int vector[40];




struct person
{
    int id;
    char nume[20];
};

person persoane[100];

//alocare dinamica
char *sir  = malloc(100*sizeof(char));
if (sir == NULL)
{
    perror("Sunt in malloc");
    exit(EXIT_FAILURE)

}


free(sir);








