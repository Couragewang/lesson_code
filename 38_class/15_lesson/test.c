#include <stdio.h>
#include <signal.h>

volatile int flag = 0;

void handler(int signo)
{
    printf("get a sig: %d\n", signo);
    flag = 1;
}

int main()
{
    signal(2, handler);
    while(!flag);
    printf("main quit!\n");
}
