#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main()
{
    daemon(0,0);
    while(1){
        sleep(1);
    }

//    cout << "proc is running" << endl;
//    pid_t id = fork();
//    if(id == 0){
//        while(1){
//            cout << "I am child ..." << endl;
//            sleep(1);
//        }
//    }else{
//        sleep(3);
//        exit(1);
//    }
    return 0;
}
