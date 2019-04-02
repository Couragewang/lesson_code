#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class UdpClient{
    private:
        int sock;
        std::string server_ip;
        int server_port;
    public:
        UdpClient(std::string ip_, int port_):server_ip(ip_), server_port(port_)
        {
        }
        void InitClient()
        {
            sock = socket(AF_INET, SOCK_DGRAM, 0);
            if(sock < 0){
                std::cerr << "socket error" << std::endl;
                exit(2);
            }

          //  if(bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0){
          //      std::cerr << "bind error" << std::endl;
          //      exit(3);
          //  }
        }
        void recvData(std::string &out)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
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
        void sendData(std::string &in)
        {
            struct sockaddr_in server;
            server.sin_family = AF_INET;
            server.sin_port = htons(server_port);
            server.sin_addr.s_addr = inet_addr(server_ip.c_str());

            sendto(sock, in.c_str(), in.size(), 0, (struct sockaddr*)&server, sizeof(server));
        }
        void Start()
        {
            std::string str;
            std::string out;
            for(;;){
                std::cout << "Please Enter# ";
                std::cin >> str;
                sendData(str);
                recvData(out);
                std::cout << "server echo# " << out << std::endl;
            }
        }
        ~UdpClient()
        {
            close(sock);
        }
};

void Usage(std::string proc)
{
    std::cout << "Usage: " << proc << " server_ip server_port" << std::endl;
}
// ./client serverip sreverport
int main(int argc, char *argv[])
{
    if(argc != 3){
        Usage(argv[0]);
        exit(1);
    }
    std::string ip = argv[1];
    int port = atoi(argv[2]);
    UdpClient client(ip, port);
    client.InitClient();
    client.Start();

    return 0;
}

















