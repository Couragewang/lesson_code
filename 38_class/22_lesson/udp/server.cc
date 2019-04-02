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
        UdpServer(std::stirng ip_, int port_):ip(ip_), port(port_)
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
        void recvData(std::string &out)
        {
            char buf[1024];
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            ssize_t s = recvfrom(sock, buf, sizeof(buf)-1, 0, \
                    (struct sockaddr*)&peer, &len);
            if(s > 0){
                buf[s] = 0;
                out = buf;
            }else{

            }
        }

        ~UdpServer()
        {
            close(sock);
        }
};

int main()
{

    return 0;
}

















