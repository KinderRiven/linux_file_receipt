#include "crecvserver.h"

/*
 *  Create Receive Server
 */
crecvServer::crecvServer(int port)
{
    DEBUG = true;
    this->port = port;
    strcpy(outFileName, "outFile");
}

/*
 * Prepare
 */
bool crecvServer::start(){

    socket_server = socket(AF_INET, SOCK_STREAM, 0);

    bzero((void*)&addr, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(socket_server, (sockaddr *)&addr, sizeof(addr)) < 0){
        if(DEBUG)
            printf("Bind error...\n");
        return false;
    }

    if(listen(socket_server, 5) < 0){
        if(DEBUG)
            printf("Listening error...\n");
        return false;
    }

    loopListening();
    return true;
}


/*
 * Receving
 */
void crecvServer::startRecving(char *name){

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

    char buffer[BUFFER_SIZE];


    QFile::remove(name);

    int fw = open(name, O_WRONLY | O_CREAT);
    sprintf(buffer, "chmod 777 %s", name);
    system(buffer);

    while(1){

        int write_len, L, read_len = read(socket_client, buffer, BUFFER_SIZE);
        char *pr = buffer;

        L = read_len;
        if(read_len <= 0)
            break;
        while((write_len = write(fw, pr, L)) >= 0){

            if(write_len == L)
                break;
            pr += write_len;
            L  -= write_len;
        }
    }
    if(DEBUG)
        printf("Send well...\n");
    close(fw);
    close(socket_client);
}

/*
 * Listening
 */
void crecvServer::loopListening(){
    socklen_t socket_len = sizeof(caddr);


    while(1){

        if(DEBUG)
            printf("Waiting...\n");

        socket_client = accept(socket_server, (sockaddr*)&caddr, &socket_len);

        if(DEBUG)
            printf("Start recving...\n");

        startRecving(outFileName);
    }
}
