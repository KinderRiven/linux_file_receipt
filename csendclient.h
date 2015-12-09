#ifndef CSENDCLIENT_H
#define CSENDCLIENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

class csendClient
{

public:
    csendClient(const char *ip = NULL, const char *file = NULL, int port = 2048);
    bool startRun();

private:
    char ip[128];
    char file[128];
    int port;
    bool DEBUG;
};

#endif // CSENDCLIENT_H
