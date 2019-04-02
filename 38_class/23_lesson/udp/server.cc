#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class UdpServer{
    private:
        int sock;
        std::string ip;
        int port;
    public:
        UdpServer(std::string ip_, int port_):ip(ip_), port(port_)
        {
        }
        void InitServer()
        {
            sock = socket(AF_INET, SOCK_DGRAM, 0);
            if(sock < 0){
                std::cerr << "socket error" << std::endl;
                exit(2);
            }
            struct sockaddr_in local;
            local.sin_family = AF_INET;
            local.sin_port = htons(port);
            local.sin_addr.s_addr = inet_addr(ip.c_str());

            if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0){
                std::cerr << "bind error" << std::endl;
                exit(3);
            }
        }
        void recvData(std::string &out, struct sockaddr_in &peer, socklen_t &len)
        {
            char buf[1024];
            ssize_t s = recvfrom(sock, buf, sizeof(buf)-1, 0, \
                    (struct sockaddr*)&peer, &len);
            if(s > 0){
                buf[s] = 0;
                out = buf;
            }else{
                std::cerr << "recvform error!" << std::endl;
            }
        }
        void sendData(std::string &in, struct sockaddr_in &peer)
        {
            sendto(sock, in.c_str(), in.size(), 0, (struct sockaddr*)&peer, sizeof(peer));
        }
        void Start()
        {
            std::string str;
            struct sockaddr_in peer;
            socklen_t len = 0;
            std::string suffix = " + UdpServer";
            for(;;){
                len = sizeof(peer);
                recvData(str, peer, len);
                str += suffix;
                std::cout << str << std::endl;
                sendData(str, peer);
            }
        }
        ~UdpServer()
        {
            close(sock);
        }
};

void Usage(std::string proc)
{
    std::cout << "Usage: " << proc << " ip port" << std::endl;
}
// ./server ip port
int main(int argc, char *argv[])
{
    if(argc != 3){
        Usage(argv[0]);
        exit(1);
    }
    std::string ip = argv[1];
    int port = atoi(argv[2]);
    UdpServer server(ip, port);
    server.InitServer();

//    daemon(0, 0);
    server.Start();

    return 0;
}

















