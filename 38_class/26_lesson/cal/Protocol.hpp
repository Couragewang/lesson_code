#pragma once

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

//定长方案
typedef struct Request{
    int x;
    int y;
    char op;
}request_t;

typedef struct Response{
    int status;
    int result;
}response_t;
