#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

class BlockQueue{
    private:
        std::queue<int> q;
        bool water_line;
        pthread_mutex_t lock;
        pthread_cond_t cond;
    private:
        void LockQueue()
        {
            water_line = false;
            pthread_mutex_lock(&lock);
        }
        void UnlockQueue()
        {
            pthread_mutex_unlock(&lock);
        }
        bool IsEmpty()
        {
            return q.size() == 0 ? true : false;
        }
        void ThreadWait()
        {
            pthread_cond_wait(&cond, &lock);
        }
        void WakeupOneThread()
        {
            pthread_cond_signal(&cond);
        }
        void UpdateWaterLine()
        {
            if(q.size() >= 5){
                water_line = true;
            }
            else{
                water_line = false;
            }
        }
    public:
        BlockQueue()
        {
            pthread_mutex_init(&lock, NULL);
            pthread_cond_init(&cond, NULL);
        }
        void PushData(const int &data)
        {
            LockQueue();
            q.push(data);
            UpdateWaterLine();
            if(water_line){
                WakeupOneThread();
            }
            UnlockQueue();
            std::cout << "producter run done, data push success: " << data << " wake up thread done..."<< std::endl;
        }
        void PopData(int &data)
        {
            LockQueue();
            while(IsEmpty()){
            //while(!water_line){
                ThreadWait();
            }
            data = q.front();
            q.pop();
            UpdateWaterLine();
            UnlockQueue();
            std::cout << "Consumer run done, data pop success : " << data << std::endl;
        }
        ~BlockQueue()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&cond);
        }
};

void *product(void *arg)
{
    BlockQueue *bq = (BlockQueue*)arg;
    srand((unsigned long)time(NULL));
    while(1)
    {
        int data = rand()%100 + 1;
        bq->PushData(data);
        sleep(1);
    }
}

void *consume(void *arg)
{
    BlockQueue *bq = (BlockQueue*)arg;
    while(1)
    {
        int d;
        bq->PopData(d);
    }
}

int main()
{
    BlockQueue bq;

    pthread_t p, c;
    pthread_create(&p, NULL, product, (void *)&bq);
    pthread_create(&c, NULL, consume, (void *)&bq);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
}












