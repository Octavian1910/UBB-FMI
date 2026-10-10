#include <stdio.h>

/*Sa se afiseze, pentru fiecare numar de la 32 la 126, valoarea numarului (in baza 8) si caracterul cu acel cod ASCII.
*/

int baza8(int);
char cod_asci(int);
int main()
{
    for (int i = 32 ; i <= 126 ; i++)
    {
        int rez = baza8(i);
        printf("%d - ",rez);
        char caracter_in_asci = cod_asci(rez);
        printf("%c \n",rez,caracter_in_asci);
    }
    
    
    
    return 0;
}
