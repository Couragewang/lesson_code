#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PN "/tmp"
#define PJ 0x6666

int main()
{
    key_t k = ftok(PN, PJ);
    if( k < 0 ){
        printf("ftok error!\n");
        return 1;
    }

    int shmid = shmget(k, 4097, IPC_CREAT | IPC_EXCL | 0666);
    if(shmid < 0){
        perror("shmget");
        return 2;
    }
    printf("%d\n", shmid);
    char *str = (char*)shmat(shmid, NULL, 0);

    while(1){
        sleep(1);
        printf("%s\n", str);
    }

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}



















