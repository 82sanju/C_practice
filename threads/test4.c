#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* taskA(void* arg) {
    printf("Task A start\n");
    sleep(2);
    printf("Task A end\n");
    return NULL;
}

void* taskB(void* arg) {
    printf("Task B start\n");
    sleep(2);
    printf("Task B end\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, taskA, NULL);
    pthread_create(&t2, NULL, taskB, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}