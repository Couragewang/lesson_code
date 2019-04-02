#include <iostream>
#include <pthread.h>
#include <unistd.h>

int data = 0;
pthread_rwlock_t rw;

void *reader(void *arg)
{
    for(;;)
    {
        pthread_rwlock_rdlock(&rw);
        std::cout << "reader read done : " << data << std::endl;
        pthread_rwlock_unlock(&rw);
    }
}

void *writer(void *arg)
{
    for(;;){
        pthread_rwlock_wrlock(&rw);
        std::cout << "writer write done : " << ++data << std::endl;
        pthread_rwlock_unlock(&rw);
    }
}

int main()
{
    pthread_rwlock_init(&rw, NULL);

    pthread_t r[5], w;
    pthread_create(&r[0], NULL, reader, NULL);
    pthread_create(&r[1], NULL, reader, NULL);
    pthread_create(&r[2], NULL, reader, NULL);
    pthread_create(&r[3], NULL, reader, NULL);
    pthread_create(&r[4], NULL, reader, NULL);
    pthread_create(&w, NULL, writer, NULL);

    for(auto i=0; i < 5;i++){
        pthread_join(r[i], NULL);
    }
    pthread_join(w, NULL);

    pthread_rwlock_destroy(&rw);
    return 0;
}













