#include <stdio.h>


int asmConcat(char sir[],char sirR[]);

void citireSirC(char sir[]);


char str3[] = "0011223344";

int main()
{
    char sir1[11];
    char StrRez[31] = "";
    citireSirC(sir1);
    
    int lenStrRez = asmConcat(str1,strRez)
    printf("Sirul rezultat de lungime %d : \n %s,lenStrRez",strRez);
    
    
        lenStrUpp=asmUpper(lenStrRez,strRez,strUpp);
    printf("\nSirul rezultat de lungime %d:\n%s", lenStrUpp, strUpp);
    
    return 0;
    
  
}

void citireSirC(char sir[])
{
    scanf("%s",sir);
}