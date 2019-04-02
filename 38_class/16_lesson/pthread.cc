#include <iostream>
#include <unistd.h>
#include <pthread.h>

void *ThreadRun(void *arg)
{
    sleep(2);
    pthread_detach(pthread_self());
    //pthread_cancel(pthread_self());
    int i = 0;
    while(1){
        std::cout << "I am New thread, No. is " << pthread_self()<< std::endl;
        sleep(2);
        i++;
        if(i == 3){
            break;
        }
    }
    std::cout << "new thread quit" << std::endl;
 //   return (void *)11;
}

int main()
{
    pthread_t  tid;
    pthread_create(&tid, NULL, ThreadRun, NULL);
    sleep(3);
    void *status;
    int ret = pthread_join(tid, &status);

    std::cout << "main pthread done, new status : " << (int)status << "ret: "<< ret << std::endl;
}






