#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t printers;

void *job(void *arg) {
    int id = *(int *)arg;
    sem_wait(&printers);
    printf("Job %d is printing\n", id);
    sleep(2);
    printf("Job %d done\n", id);
    sem_post(&printers);
    return NULL;
}

int main() {
    pthread_t t[4];
    int ids[4] = {1, 2, 3, 4};
    sem_init(&printers, 0, 2);
    for (int i = 0; i < 4; i++)
        pthread_create(&t[i], NULL, job, &ids[i]);
    for (int i = 0; i < 4; i++)
        pthread_join(t[i], NULL);
    sem_destroy(&printers);
    return 0;
}
