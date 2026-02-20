#include <stdio.h>

/*Se citesc mai multe siruri de caractere. Sa se determine daca primul apare ca subsecventa in fiecare din celelalte si sa se dea un mesaj corespunzator.Daca se introduce stop ne oprim
*/

int e_subsecventa(char sir[],char sir2[]);

int main()
{
    char sir[100];
    fgets(sir,100,stdin);
    int ok = 1;    //daca e 1 e ok daca e 0 nu apare
    while(1)
    {
        char sir2[100];
        fgets(sir2,100,stdin);
        if(strcmp(sir2,"stop\n") == 0)
        {
            break;
        }
        else
        {
            if(e_subsecventa(sir,sir2) == 0)
                ok = 0;
            
        }
    }
    
    if(ok == 1)
    {
        printf("Este subsecventa");
    }
    else
    {
        printf("Nu este subsecventa");
    }
    return 0;
}
