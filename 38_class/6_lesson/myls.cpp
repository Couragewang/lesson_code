#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

using namespace std;
int main()
{
    cout << "hello ls" << endl;
    //while(1)
  //  pid_t id = fork();
  //  if(id == 0){ //child
  //      while(1){
  //          cout << "I am child, pid is : " << getpid() << endl;
  //          sleep(1);
  //      }
  //  }else{ //parent
  //      int count = 0;
  //      while(1){
  //          cout << "I am parent, pid is : " << getpid() << endl;
  //          sleep(1);
  //          count++;
  //          if(count == 5){
  //              cout << "child quit!" << endl;
  //              exit(0);
  //          }
  //      }
  //  }

//    while(1)
//    {
//
//    }
//    std::cout << "begin!" << std::endl;
//    pid_t id = fork();
//    if(id < 0){
//        std::cout << "fork error" << std::endl;
//        return 1;
//    }
//    else if(id == 0){ //child
//        while(1){
//            sleep(1);
//            std::cout << "I am a child " << getpid() << std::endl;
//        }
//    }else{ //parent
//        while(1){
//            sleep(1);
//            std::cout << "I am a parent " << getpid() << std::endl;
//        }
//    }
    return 0;
}
