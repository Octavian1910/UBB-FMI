#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THR 100
#define MAX_NUM 100000

int suma = 0;
int* numere;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


//thread start routine
void* do_sum(void* arg)
{
    int id = *(int*)arg;
    free(arg);

    //calculez limitele
    int left = id * (MAX_NUM / MAX_THR);
    int right = left + (MAX_NUM / MAX_THR);

    for(int i = left; i < right; i++)
    {
        pthread_mutex_lock(&mtx);
        suma += numere[i];
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

//1. Generați 100.000 de numere aleatoare și calculați suma lor utilizând 100 thread-uri.
int main(int argc, char* argv[])
{
    //aloc dinamic tabloul de numere
    numere = malloc(MAX_NUM * sizeof(int));

    if(numere == NULL)
    {
        perror("malloc()");
        exit(1);
    }

    //generez numere aleatoare
    for(int i = 0; i < MAX_NUM; ++i)
    {
        numere[i] = rand() % 100;
    }

    //creez threadurile
    pthread_t tids[MAX_THR];

    for(int i = 0; i < MAX_THR; ++i)
    {
        int* id = malloc(sizeof(int));

        *id = i;

        pthread_create(&tids[i], NULL, do_sum, id);
    }

    //astept terminarea threadurilor
    for(int i = 0; i < MAX_THR; ++i)
    {
        pthread_join(tids[i], NULL);
    }

    //afisez rezultatul
    int suma_verificata = 0;

    for(int i = 0; i < MAX_NUM; ++i)
    {
        suma_verificata += numere[i];
    }

    printf("Suma: %d\n", suma);
    printf("Suma 2: %d\n", suma_verificata);

    free(numere);

    return 0;
}
