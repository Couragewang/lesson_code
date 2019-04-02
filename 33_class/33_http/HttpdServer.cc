#include "HttpdServer.hpp"
#include <signal.h>
#include <unistd.h>

static void Usage(std::string proc_)
{
    std::cout << "Usage " << proc_ << " port" << std::endl;
}
//./HttpdServer 8080
int main(int argc, char *argv[])
{
    if(argc != 2){
        Usage(argv[0]);
        exit(1);
    }

    signal(SIGPIPE, SIG_IGN);
    HttpdServer *serp = new HttpdServer(atoi(argv[1]));
    serp->InitServer();
//    daemon(1, 0);
    serp->Start();

    delete serp;
    return 0;
}
