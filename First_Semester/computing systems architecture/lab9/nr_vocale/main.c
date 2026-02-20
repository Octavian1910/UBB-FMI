#include <stdio.h>
#include <string.h>


/*
citeste cuvinte pana intalnesti stop
inlocuieste cuvintele cu nr de vocale
*/

void litere_mici(char sir[],char rez[]);
void litere_mari(char sir[],char rez[]);



int main()
{
    while(1)
    {
       fgets(sir,100,stdin);
       if(strcmp(sir,"stop\n") == 0)
           break;
       
       printf("Nr vocale : %d \n ",nr_vocale(sir));
       
    }

    
    return 0;
}
