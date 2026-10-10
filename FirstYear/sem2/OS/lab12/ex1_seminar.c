


#include <pthread.h>

pthread_barrier_t barr;

void* do_something(void* arg)
{
    //calcule etapa 1
    pthread_barrier_wait(&barr);

    //calcule etapa 2


    //pthread_barrier_wait(&barr); daca pui aici merge pt ca valoarea este reinitializata automat

}


int main()
{
    //initializez bariera
    pthread_barrier_init(&barr,NULL,50); //atentie mare aici sa fie neaparat numarul potrivit de bariere


    //creez threadurile
}
