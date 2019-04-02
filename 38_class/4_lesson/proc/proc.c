#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int i = 1;
    char bar[101];
    memset(bar, '\0', sizeof(bar));
    const char *lable="|/-\\";
    while(i<=100){
        bar[i-1] = '#';
        printf("[%-100s][%d%%][%c]\r", bar, i, lable[(i-1)%4]);
        fflush(stdout);
        i++;
        usleep(50000);
    }
    printf("\n");
    return 0;
}
