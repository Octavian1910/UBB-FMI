#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_THR 10

#define E_GOL  0
#define E_PLIN 1

int buffer[MAX_SIZE];
int suma = 0;
int stare = E_GOL;

// obiecte de sincronizare
pthread_cond_t vcc = PTHREAD_COND_INITIALIZER;
pthread_cond_t vcp = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


// PRODUCATOR
void* produc(void* arg)
{
    int id = *(int*)arg;
    free(arg);

    pthread_mutex_lock(&mtx);

    while (stare == E_PLIN)
    {
        pthread_cond_wait(&vcp, &mtx);
    }

    // produc
    printf("Producator %d produce...\n", id);

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        buffer[i] = rand() % 256;
    }

    stare = E_PLIN;

    pthread_cond_signal(&vcc);

    pthread_mutex_unlock(&mtx);

    return NULL;
}


// CONSUMATOR
void* consum(void* arg)
{
    int id = *(int*)arg;
    free(arg);

    pthread_mutex_lock(&mtx);

    while (stare == E_GOL)
    {
        pthread_cond_wait(&vcc, &mtx);
    }

    // consum
    printf("Consumator %d consuma...\n", id);

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        suma += buffer[i];
    }

    stare = E_GOL;

    pthread_cond_signal(&vcp);

    pthread_mutex_unlock(&mtx);

    return NULL;
}


int main()
{
    srand(time(NULL));

    pthread_t tc[MAX_THR];
    pthread_t tp[MAX_THR];

    // creez consumatori
    for (int i = 0; i < MAX_THR; ++i)
    {
        int* idc = malloc(sizeof(int));
        *idc = i;

        pthread_create(&tc[i], NULL, consum, idc);
    }

    // creez producatori
    for (int i = 0; i < MAX_THR; ++i)
    {
        int* idp = malloc(sizeof(int));
        *idp = i;

        pthread_create(&tp[i], NULL, produc, idp);
    }

    // astept threadurile
    for (int i = 0; i < MAX_THR; ++i)
    {
        pthread_join(tc[i], NULL);
        pthread_join(tp[i], NULL);
    }

    printf("\nSuma finala: %d\n", suma);

    return 0;
}