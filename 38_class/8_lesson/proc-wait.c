#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    execl("/usr/bin/ls", "ls", "-l", "-i", "-a", NULL);
//    pid_t id = fork();
//    if(id == 0){//child
//        sleep(30);
//        printf("child: pid : %d, ppid: %d, exit begin...\n", getpid(), getppid());
//        //int *p = NULL;
//        //*p =100;
//        exit(19);
//    }else{//father
//        sleep(10);
//        int status;
//        printf("father: pid : %d, ppid: %d, wait begin...\n", getpid(), getppid());
//        pid_t id_ = waitpid(id, &status, 0);
//        printf("father wait success, id is : %d\n", id_);
//        if(status & 0x7F){
//            printf("father wait success, sig is : %d\n", status & 0x7F);
//        }
//        else{
//            printf("father wait success, exit code is : %d\n", (status >> 8)&0xFF);
//        }
//        sleep(5);
//    }
    return 0;
}

