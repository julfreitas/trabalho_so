#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS_LEITURA 14
#define NUM_THREADS_ESCRITA 2
#define TABLE_SIZE 100

int table[TABLE_SIZE]; //criando onde os dados são armazenados
pthread_rwlock_t rwlock; //trava que permite o acesso seguro à tabela por meio de threads leitoras e escritas

//função executada por cada thread leitora
void* reader(void* arg) { 
    int thread_id = *(int*)arg;

    // Realiza leitura da tabela
    pthread_rwlock_rdlock(&rwlock); //trava de leitura para permitir que apenas uma thread leitora por vez pode entrar na seção crítica e que múltipas threads leiam simultaniamente a tabela
    printf("Thread leitora %d lendo a tabela\n", thread_id);
    // Lógica de leitura da tabela
    pthread_rwlock_unlock(&rwlock); //trava é liberada

    pthread_exit(NULL); //encerrar execução da thread leitora
}

//função executada por cada thread escritora
void* writer(void* arg) {
    int thread_id = *(int*)arg;

    // Realiza escrita na tabela
    pthread_rwlock_wrlock(&rwlock); //trava de escrita para garantir exclusão mútua
    printf("Thread escritora %d escrevendo na tabela\n", thread_id);
    // Lógica de escrita na tabela
    pthread_rwlock_unlock(&rwlock); //trava é liberada

    pthread_exit(NULL); //encerrar execução da thread leitora
}

int main() {
    pthread_t readers[NUM_THREADS_LEITURA]; //identificação das threads leitoras
    pthread_t writers[NUM_THREADS_ESCRITA]; //identificação das threads escritoras
    int reader_ids[NUM_THREADS_LEITURA];
    int writer_ids[NUM_THREADS_ESCRITA];

    // Inicializa o rwlock
    pthread_rwlock_init(&rwlock, NULL);

    // Cria threads leitoras
    for (int i = 0; i < NUM_THREADS_LEITURA; i++) {
        reader_ids[i] = i;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Cria threads escritoras
    for (int i = 0; i < NUM_THREADS_ESCRITA; i++) {
        writer_ids[i] = i;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Aguarda as threads leitoras terminarem
    for (int i = 0; i < NUM_THREADS_LEITURA; i++) {
        pthread_join(readers[i], NULL);
    }

    // Aguarda as threads escritoras terminarem
    for (int i = 0; i < NUM_THREADS_ESCRITA; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroi o rwlock
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
