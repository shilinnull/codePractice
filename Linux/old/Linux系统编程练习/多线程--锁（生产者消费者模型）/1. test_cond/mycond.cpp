#include <iostream>
#include <unistd.h>
#include <pthread.h>

// 临界资源
int cnt = 0;

// 初始化
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *Count(void *args)
{
    uint64_t number = (uint64_t)args;
    std::cout << "pthread: " << number << " create sucess! " << std::endl;

    while (true)
    {
        // 加锁
        pthread_mutex_lock(&mutex);
        // 必须先加锁后等待
        pthread_cond_wait(&cond, &mutex);

        std::cout << "pthread: " << number << ", cnt: " << cnt++ << std::endl;
        // 解锁
        pthread_mutex_unlock(&mutex);
    }
    // 分离线程
    pthread_detach(pthread_self());
}

int main()
{
    for (uint64_t i = 0; i < 5; i++)
    {
        pthread_t tid;
        pthread_create(&tid, nullptr, Count, (void *)i); // 注意这里细节不能传i的地址
        usleep(1000);                                    // 创建出来的线程打印就保持一致了
    }

    sleep(3);
    std::cout << "main thread ctrl begin: " << std::endl;

    while (true)
    {
        sleep(1);
        // 唤醒单个线程
        // pthread_cond_signal(&cond);
        // std::cout << "signal thread..." << std::endl;

        // 唤醒多个线程
        pthread_cond_broadcast(&cond);
        std::cout << "boardcast thread..." << std::endl;
    }

    return 0;
}