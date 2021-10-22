#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10000
int saldo;
pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER;

void * suma100(void *arg){
    int lsaldo;
    pthread_mutex_lock(&saldoLock);
    lsaldo = saldo; //2
    lsaldo += 100; //2
    saldo = lsaldo; //2
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0; //2
    char *s = "Soy un argumento";
    //int d = 20;
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, suma100, NULL/*(void *) s*/); //2
    }
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL); //2
    }
    printf("Saldo final es %d\n", saldo); //2
    pthread_exit(NULL);
    //return 0;
}