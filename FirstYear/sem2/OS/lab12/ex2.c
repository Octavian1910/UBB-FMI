#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define E_GOL 0
#define E_PLIN 1

#define MAX_SIZE 100

int buffer[MAX_SIZE];
int stare = E_GOL;

int suma = 0;

/*
    mtp + vcp -> producatori
    mtc + vcc -> consumatori
*/

pthread_mutex_t mtp = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mtc = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t vcp = PTHREAD_COND_INITIALIZER;
pthread_cond_t vcc = PTHREAD_COND_INITIALIZER;


// PRODUCER
void* produc(void* arg)
{
    pthread_mutex_lock(&mtp);

    while (stare == E_PLIN)
    {
        pthread_cond_wait(&vcp, &mtp);
    }

    printf("Producer produce...\n");

    for (int i = 0; i < MAX_SIZE; i++)
    {
        buffer[i] = rand() % 100;
    }

    stare = E_PLIN;

    pthread_cond_signal(&vcc);

    pthread_mutex_unlock(&mtp);

    return NULL;
}


// CONSUMER
void* consum(void* arg)
{
    pthread_mutex_lock(&mtc);

    while (stare == E_GOL)
    {
        pthread_cond_wait(&vcc, &mtc);
    }

    printf("Consumer consuma...\n");

    int suma_locala = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        suma_locala += buffer[i];
    }

    suma += suma_locala;

    printf("Suma partiala = %d\n", suma_locala);

    stare = E_GOL;

    pthread_cond_signal(&vcp);

    pthread_mutex_unlock(&mtc);

    return NULL;
}


int main()
{
    pthread_t prod, cons;

    srand(getpid());

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&prod, NULL, produc, NULL);
        pthread_create(&cons, NULL, consum, NULL);

        pthread_join(prod, NULL);
        pthread_join(cons, NULL);
    }

    printf("\nSuma finala = %d\n", suma);

    return 0;
}