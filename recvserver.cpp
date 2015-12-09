#include "recvserver.h"

recvServer::recvServer(QWidget *parent)
    : QWidget(parent)
{
    DEBUG = true;
    this->port = 2048;

    //connect
    connect(&tcpServer, SIGNAL(newConnection()),
            this, SLOT(newConnectionSlot()));
}

recvServer::~recvServer(){

}

void recvServer::newConnectionSlot(){
    if(DEBUG)
        printf("Find new connnecting...\n");
}

bool recvServer::start(){
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
