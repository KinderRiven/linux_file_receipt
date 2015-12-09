#include "recvfileserver.h"

recvFileServer::recvFileServer(QWidget *parent)
    : QWidget(parent)
{
    DEBUG = true;
    this->port = 2048;
}

recvFileServer::~recvFileServer(){

}

void recvFileServer::newConnectionSlot(){
    if(DEBUG)
        printf("Find new connnecting...\n");
}

bool recvFileServer::start(){
    if(tcpServer.isListening()){
        if(DEBUG)
            printf("Already listening!\n");
        return false;
    }
    else{
        if(tcpServer.listen(QHostAddress::Any, port)){
            if(DEBUG)
                printf("Listening well!\n");
            return true;
        }
        else{
            if(DEBUG)
                printf("Listening error!\n");
            return false;
        }
    }
}
