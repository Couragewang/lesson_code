#include <iostream>
#include "Protocol.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2){
        cerr << "Usage: " << argv[0] << " ip" << endl;
        exit(1);
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(8888);
    peer.sin_addr.s_addr = inet_addr(argv[1]);



    if(connect(sock, (struct sockaddr*)&peer, sizeof(peer))<0){
        cerr << "connect error!" << endl;
        exit(2);
    }

    for(;;){
        request_t rq;
        response_t rsp;
        cout << "Please Enter x op y[0 q 0=quit]]:";
        cin >> rq.x >> rq.op >> rq.y;
        send(sock, &rq, sizeof(rq), 0);
        if(rq.op == 'q'){
            break;
        }
        recv(sock, &rsp, sizeof(rsp), 0);
        cout << "status: "<<rsp.status << endl;
        cout << "result: "<<rsp.result << endl;
    }

    close(sock);
}








