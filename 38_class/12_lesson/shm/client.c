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

    int shmid = shmget(k, 4097, IPC_CREAT);
    if(shmid < 0){
        perror("shmget");
        return 2;
    }
    printf("%d\n", shmid);
    char *str = (char*)shmat(shmid, NULL, 0);

    char x = 'A';
    while(x <= 'Z'){
        str[x-'A'] = x;
        x++;
        str[x-'A'] = 0;
        sleep(5);
    }

    shmdt(str);
    return 0;
}



















