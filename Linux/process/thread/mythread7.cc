#include <iostream>
#include <pthread.h>
#include <unistd.h>


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

bool falg = false;

void *printA(void* args)
{
    for(;;)
    {
        pthread_mutex_lock(&lock);
        while(falg)
            pthread_cond_wait(&cond, &lock);
        falg = true;
        printf("打印A\n");
        pthread_mutex_unlock(&lock);
        sleep(1);
    }        
}

void *printB(void* args)
{
    for(;;)
    {
        pthread_mutex_lock(&lock);
        while(!falg)
            pthread_cond_wait(&cond, &lock);
        falg = false;
        printf("打印B\n");
        pthread_mutex_unlock(&lock);
        sleep(1);
    }        
}

int main()
{
    pthread_t a, b;
    pthread_create(&a, nullptr, printA, nullptr);
    pthread_create(&b, nullptr, printB, nullptr);

    pthread_join(a, nullptr);
    pthread_join(b, nullptr);
    return 0;
}
