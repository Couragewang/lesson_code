#include <iostream>
#include "ChatClient.hpp"

static void Usage(std::string proc)
{
    std::cout << "Usage: " << proc << " peer_ip" << std::endl;
}
static void Menu(int &s)
{
    std::cout << "###########################################" << std::endl;
    std::cout << "###  1. Register               2. Login  ##" << std::endl;
    std::cout << "##                             3. Exit   ##" << std::endl;
    std::cout << "###########################################" << std::endl;
    std::cout << "Please Select:> ";
    std::cin >> s;
}

// ./ChatClient ip
int main(int argc, char *argv[])
{
    if(argc != 2){
        Usage(argv[0]);
        exit(1);
    }
    ChatClient *cp = new ChatClient(argv[1]);
    cp->InitClient();
    int select = 0;
    while(1){
        Menu(select);
        switch(select){
            case 1: //Register
                cp->Register();
                break;
            case 2: //Login
                if(cp->Login()){
                    cp->Chat();
                    cp->Logout();
                }else{
                    std::cout << "Login Failed!" << std::endl;
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                exit(1);
                break;
        }
    }



   // if(cp->ConnectServer()){
   //     std::cout << "connect success!" << std::endl;
   // }
}

