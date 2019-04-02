#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//int b;
//int a = 100;

int g_val = 100;

int main(int argc, char *argv[])
{
    pid_t id = fork();
    if(id == 0){ //child
        g_val = 200;
        printf("child: g_val: %d, &g_val: %p\n", g_val, &g_val);
    }
    else{//father
        sleep(3);
        printf("father: g_val: %d, &g_val: %p\n", g_val, &g_val);

    }



//    printf("code addr : %p\n", main);
//    const char *msg = "hello bit";
//    printf("readonly addr : %p\n", msg);
//    printf("init addr : %p\n", &a);
//    printf("uninit addr : %p\n", &b);
//    char *mem = (char*)malloc(10);
//    printf("heap addr : %p\n", mem);
//
//    printf("stack addr : %p\n", &mem);
//
//    printf("%s\n", getenv("PATH"));
//    putenv("PATH=/A/B/C:/D/E/F:");
//    int i = 0;
//    for(; env[i]; i++){
//        printf("%d:%s\n", i, env[i]);
//    }
////    int i = 0;
//    for(; i < argc; i++){
//        printf("%d: %s\n", i, argv[i]);
//    }
    return 0;
}

