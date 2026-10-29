#include <stdio.h>
#include <pthread.h>

pthread_t t;

void *task(void *arg) {
    printf("Thread created\n");
    pthread_exit(NULL);
}

int main() {
    pthread_create(&t, NULL, task, NULL);

    if(pthread_equal(pthread_self(), t))
        printf("Threads are equal\n");
    else
        printf("Threads are different\n");

    pthread_join(t, NULL);
    printf("Thread joined\n");
    printf("Thread exited\n");

    return 0;
}