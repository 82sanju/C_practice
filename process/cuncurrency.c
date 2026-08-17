#include <stdio.h>
#include <pthread.h>

void* task(void* arg) {
    printf("Thread running\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}