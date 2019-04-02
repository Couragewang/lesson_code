#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char buf[1024];
    ssize_t s = read(0, buf, sizeof(buf));
    if(s > 0){
        buf[s-1] = 0;
        write(1, buf, strlen(buf));
    }
//    close(1);
//    int fd0 = open("./log0.txt", O_WRONLY|O_CREAT, 0644);
//    printf("fd0: %d\n", fd0);
//
//    printf("hello world!\n");
//    printf("hello world!\n");
//    printf("hello world!\n");
//    printf("hello world!\n");
//    printf("hello world!\n");
//    printf("hello world!\n");
//
//    fflush(stdout);
//    close(fd0); //fclose();
    return 0;
}
