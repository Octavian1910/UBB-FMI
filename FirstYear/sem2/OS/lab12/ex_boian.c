
//pb 27 de pe site


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

char sir[MAX_SIZE];
int contor = 1;
int poz_sir = 0;

vooid* generate(void* arg)
{
    while (1)
    {
        char chr = 'a' + rand() % ('z'-'a' + 1);

        if (poz_sir == MAX_SIZE)
        {

        }

        if (contor == M)
        {
            break;
        }

        sir[poz_sir] = chr;
        poz_sir++;

    }
}



int main(int argc,char** argv)
{
    if (argv != 2)
    {
        printf("Nu au fost date argumente!\n");
        exit(1);
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    pthread_t tg[N];
    for (int i = 0 ; i < N ; ++i)
    {
        pthread_create(&tg[i],NULL,generate,NULL);
    }

    pthread_t tp;
    pthread_create(&tp,NULL,print,NULL);

    for (int i = 0 ; i < N ; ++i)
    {
        pthread_join(tp,NULL);
    }

    return 0;
}
