#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
int i = 0;

void handler(int signo)
{
    printf("count is : %d\n", i);
    exit(2);
}

// ./a.out 1234 9
int main(int argc, char *argv[])
{
    alarm(1);
    signal(SIGALRM, handler);
    for(;;){
        i++;
//        printf("%d\n", i++);
    }
    return 0;
}
