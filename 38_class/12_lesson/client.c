#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("./fifo", O_WRONLY);
    if(fd < 0){
        perror("read");
        return 2;
    }

    char buf[1024];
    while(1){
        printf("Please Enter: ");
        scanf("%s", buf);
        write(fd, buf, strlen(buf));
    }

    close(fd);
    return 0;
}
