#include <iostream>
#include <string>
#include "Protocol.hpp"

using namespace std;

int StartUp(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        cerr << "socket error" << endl;
        exit(1);
    }

    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0){
        cerr << "bind error!" << endl;
        exit(2);
    }

    if(listen(sock, 2) < 0){
        cerr << "listen error" << endl;
        exit(3);
    }

    return sock;
}

void *HandlerRequest(void *arg)
{
    int *sockp = (int*)arg;
    int sock = *sockp;
    delete sockp;

    pthread_detach(pthread_self());

    char buf[10240];
    recv(sock, buf, sizeof(buf), 0);

    cout << "####################################"<< endl;
    cout << buf << endl;
    cout << "####################################"<< endl;

    std::string echo_http="HTTP/1.0 302 REDIRECT\r\nContent-Type: text/html\r\nLocation: https://www.qq.com\r\n<html><h1>hello my Web!</h1></html>\r\n";
  //  send(sock, echo_http.c_str(), echo_http.size(), 0);

//    close(sock);

    //for(;;){
    //    request_t rq;
    //    response_t rsp = {0, 0};
    //    recv(sock, &rq, sizeof(rq), 0);
    //    cout << "get a new request: " << rq.x << rq.op << rq.y << endl;
    //    switch(rq.op){//+-*/%
    //        case '+':
    //            rsp.result = rq.x + rq.y;
    //            break;
    //        case '-':
    //            rsp.result = rq.x - rq.y;
    //            break;
    //        case '*':
    //            rsp.result = rq.x * rq.y;
    //            break;
    //        case '/':
    //            if(rq.y == 0){
    //                rsp.status = 1;
    //            }else{
    //                rsp.result = rq.x / rq.y;
    //            }
    //            break;
    //        case '%':
    //            break;
    //        case 'q':
    //            close(sock);
    //            cout << "client quit...." << endl;
    //            return (void*)0;
    //        default:
    //            rsp.status = 2;
    //            break;
    //    }
    //    send(sock, &rsp, sizeof(rsp), 0);
    //}
}

int main()
{
    int listen_sock = StartUp(8080);
    for(;;)
    {
        sleep(1);
    }
//    for(;;){
//        struct sockaddr_in peer;
//        socklen_t len = sizeof(peer);
//        int *sockp = new int;
//        sleep(1);
////        *sockp = accept(listen_sock, (struct sockaddr*)&peer, &len);
////        if(*sockp < 0){
////            cerr << "accept error!" << endl;
////            continue;
////        }
////        cout << "get a new client..." << endl;
////        pthread_t tid;
////        pthread_create(&tid, NULL, HandlerRequest, (void*)sockp);
//    }
}
