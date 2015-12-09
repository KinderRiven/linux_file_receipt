#ifndef CRECVSERVER_H
#define CRECVSERVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
//#include "messagebox.h"
#include <QFile>
#include <sys/socket.h>

class crecvServer
{
public:

    crecvServer(int port = 2048);
    bool start();
    void loopListening();
    void startRecving(char *name);

private:

    struct sockaddr_in addr;
    struct sockaddr_in caddr;
    int socket_server;
    int socket_client;
    int port;
    int is_break;
    bool DEBUG;
    char outFileName[1024];
};

#endif // CRECVSERVER_H
