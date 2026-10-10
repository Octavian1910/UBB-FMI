#define MAX_THR 50
#define MAX_NUM 100000

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <limits.h>
#include <math.h>

int* numere = NULL;

int suma_minima = 0;

pthread_mutex_t mtx;
pthread_barrier_t barr;

void* cauta_minim(void* arg)
{
    int id = *(int*)arg;
    free(arg);

    int st = id * (MAX_NUM / MAX_THR);
    int dr = st + (MAX_NUM / MAX_THR);

    int local_min = INT_MAX;

    for (int i = st; i < dr; ++i)
    {
        if (numere[i] < local_min)
        {
            local_min = numere[i];
        }
    }

    pthread_mutex_lock(&mtx);

    suma_minima += local_min;

    pthread_mutex_unlock(&mtx);

    // asteapta toate threadurile
    pthread_barrier_wait(&barr);

    float medie = (float)suma_minima / MAX_THR;

    float diferenta = fabs(medie - local_min);

    printf("Thread %d | minim = %d | media = %.2f | diferenta = %.2f\n",
           id,
           local_min,
           medie,
           diferenta);
    pthread_barrier_wait(&barr);
    return NULL;
}

int main(int argc, char* argv[])
{
    numere = malloc(MAX_NUM * sizeof(int));

    if (numere == NULL)
    {
        perror("malloc()");
        exit(1);
    }

    if (argc < 2)
    {
        printf("Nu ai dat fisier\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        perror("open()");
        exit(2);
    }

    for (int i = 0; i < MAX_NUM; ++i)
    {
        read(fd, &numere[i], sizeof(int));
    }

    close(fd);

    pthread_mutex_init(&mtx, NULL);

    pthread_barrier_init(&barr, NULL, MAX_THR);

    pthread_t tid[MAX_THR];

    for (int i = 0; i < MAX_THR; ++i)
    {
        int* id = malloc(sizeof(int));

        *id = i;

        pthread_create(&tid[i], NULL, cauta_minim, id);
    }

    for (int i = 0; i < MAX_THR; ++i)
    {
        pthread_join(tid[i], NULL);
    }

    pthread_mutex_destroy(&mtx);

    pthread_barrier_destroy(&barr);

    free(numere);

    return 0;
}