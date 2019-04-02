#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    pipe(fd);
    printf("fd[0]:fd[1] -> %d : %d\n", fd[0], fd[1]);
    pid_t id = fork();
    if(id == 0){
        //child -> write
        close(fd[0]);
        const char *msg = "A";
        int i = 0;
        while(1){
            write(fd[1], msg, strlen(msg));
            i++;
            printf("%d\n", i);
        }
    }else{
        //parent -> read
        close(fd[1]);
        char buf[1024];
        while(1){
            sleep(1);
            printf("read wait..., close read\n");
            close(fd[0]);
            break;
            ssize_t s = read(fd[0], buf, sizeof(buf));
            if(s > 0){
                buf[s] = 0;
                printf("father get a message: ");
                printf("%s\n", buf);
            }
        }
        int status = 0;
        waitpid(id, &status, 0);
        printf("%d: %d\n", status&0x7F, (status >> 8) & 0xFF);
    }
    return 0;
}
















