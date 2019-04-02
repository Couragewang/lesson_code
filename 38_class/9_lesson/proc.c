#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *const myargv[] = {
        "top",
        NULL
    };
    char *const myenv[] ={
        "MYENV=HELLOWORLD",
        NULL
    };
    //execl("./cmd", "./cmd", NULL);
    execle("./cmd", "./cmd", NULL, myenv);
    //execvp("top", myargv);
    //execlp("ls", "ls", "-a", "-l", NULL);
//    int i = 0;
//    for(; i < argc; i++){
//        printf("%d: %s\n", i, argv[i]);
//    }
}
