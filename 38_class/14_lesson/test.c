#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
    printf("AAAAAAAAAAAAAAAAAAAAAAAA: %d\n", signo);
}

void show(sigset_t *pending)
{
    int i = 1;
    for( ; i <= 31; i++ ){
        if(sigismember(pending, i)){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf("\n");
}

int main()
{
    sigset_t set, oset;
    sigemptyset(&set);
    sigemptyset(&oset);

    sigaddset(&set, 2);
    sigprocmask(SIG_SETMASK, &set, &oset);

    signal(2, handler);
    sigset_t pending;
    int i = 10;
    while(1){
        sigpending(&pending);
        show(&pending);
        sleep(1);
        if(i-- == 0){
            sigprocmask(SIG_SETMASK, &oset, NULL);
        }
    }
    return 0;
}

















