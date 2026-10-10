#include <stdio.h>
#include <string.h>
#include <unistd.h>
void with_lib()
{
    char s[64];
    char *p;
    while (1)
    {
        p = fgets(s,64,stdin);
        if (p == NULL)
        {
            break;
        }
        for (int i = 0 ; i < (int)strlen(s); i++)
        {
            if (s[i] != '\n')
            {
                s[i] = '*';

            }
        }
        fputs(s,stdout);

    }
}
///ctrl + d iesire din fisier

void with_sys()
{
    char s[64];

    while (1)
    {

       int k = read(0,s,64);
        if (k <= 0)
            break;
        for (int i = 0 ; i < k ; i++) ///majoritatea greses ca pun aici strlen
        {
            if (s[i] != '\n')
            {
                s[i] = '*';

            }
        }
        write(1,s,k);

    }
}



int main(int argc,int ** argv)
{
    if (argc > 1 && strcmp("lib",argv[1]) == 0)
    {
        with_lib();
    }
    else if (argc > 1 && strcmp("sys",argv[1]) == 0)
    {
        with_sys();
    }
    else
    {
        fputs("argument necunoscut \n",stderr);
    }
    return 0;
}

//echo $?


/*
u(ser)   g(grupul din care face parte)       o(ther)
-r/w/x          -r/w/x                          -r/w/x   (read/write/execute)
*/