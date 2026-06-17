#include <stdio.h>
#include <pthread.h>

void* thread1_func(void* arg) {

    printf("Thread 1:Hello from thread1\n");

    return NULL;
}

void* thread2_func(void* arg) {

    printf("Thread 2:Hello from thread 2\n");

    return NULL;
}

int main() {

    pthread_t t1, t2;
    pthread_create(&t1, NULL,thread1_func,NULL);

    pthread_create(&t2,NULL,thread2_func,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Main thread: Done\n");


    return 0;
}