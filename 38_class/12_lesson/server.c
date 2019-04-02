#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    if(mkfifo("./fifo", 0644) < 0){
        printf("mkfifo error!\n");
        return 1;
    }

    int fd = open("./fifo", O_RDONLY);
    if(fd < 0){
        perror("read");
        return 2;
    }

    char buf[1024];
    while(1){
        ssize_t s = read(fd, buf, sizeof(buf)-1);
        if(s > 0){
            buf[s] = 0;
            printf("client# %s\n", buf);
        }else if(s == 0){
            printf("client quit, server quit too!\n");
            break;
        }else{

        }
    }

    close(fd);
    return 0;
}
