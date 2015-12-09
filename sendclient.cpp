#include "sendclient.h"

sendClient::sendClient(QWidget *parent)
    : QWidget(parent)
{
    this->ipAddress = "127.0.0.1";
    this->port = 2048;
    DEBUG = true;
}

sendClient::~sendClient(){

}

bool sendClient::startConnect(){

    if(DEBUG)
        printf("Start Connect...\n");
    address.setAddress(ipAddress);
    tcpClient.connectToHost(address, port);
    return true;
}
