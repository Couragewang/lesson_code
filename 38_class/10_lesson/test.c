#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    const char *str1 = "hello printf\n";
    const char *str2 = "hello fwrite\n";
    const char *str3 = "helli write\n";

    printf(str1);
    fwrite(str2, 1, strlen(str2), stdout);
    write(1, str3, strlen(str3));

    fork();


   // close(1);
   // int fd = open("./log.txt", O_CREAT|O_WRONLY, 0644);
   // if(fd < 0){
   //     perror("open");
   //     return 1;
   // }

   // dup2(fd, 1);

   // printf("hello bit!\n");
   // printf("hello bit!\n");
   // printf("hello bit!\n");
   // printf("hello bit!\n");
   // fflush(stdout);

   // close(fd);
    return 0;
}
