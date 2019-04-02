#include <iostream>
#include <pthread.h>
#include <unistd.h>

int tickets = 1000;
pthread_mutex_t lock;

void *BuyTicket(void *arg)
{
    for(;;){
        pthread_mutex_lock(&lock);
        if(tickets > 0){
            usleep(1000);
            std::cout << "Get ticket success: " << tickets-- << std::endl;
        }else{
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
    }
    std::cout << "thread " << pthread_self() << "quit..." << std::endl;
}

int main()
{
    pthread_mutex_init(&lock, NULL);
    pthread_t tid[5];
    for(auto i=0; i < 5; i++){
        pthread_create(tid+i, NULL, BuyTicket, NULL);
    }

    for(auto i = 0; i < 5; i++){
        pthread_join(tid[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}














