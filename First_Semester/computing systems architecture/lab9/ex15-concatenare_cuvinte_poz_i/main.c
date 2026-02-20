#include <stdio.h>
#include <string.h>

void cuvant_cerut(char*,int,char*);

int main()
{
    int n;
    int poz = 0;
    scanf("%d",&n);
    char sir[100];
    char rezultat[100];
    fgets(sir, 100, stdin);
    for (int i = 0 ; i < n ; ++i)
    {   
        char temp[100];
        fgets(sir, 100, stdin); 
        cuvant_cerut(sir,i,temp);
        int j = 0;
        while(temp[j]!=0 && temp[j]!='\n')
        {
            rezultat[poz++] = temp[j++];
        }
            
        
        rezultat[poz++] = ' ';
        rezultat[poz] = '\0';

    }

       printf("%s",rezultat);
    
    return 0;
}

void inutil()
{
    printf("");
}


