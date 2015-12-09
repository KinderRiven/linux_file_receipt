#include "sendfileclient.h"

sendFileClient::sendFileClient(QWidget *parent)
    : QWidget(parent)
{
    this->ipAddress = "127.0.0.1";
    this->port = 2048;
}

sendFileClient::~sendFileClient(){

}

bool sendFileClient::startConnect(){

    address.setAddress(ipAddress);
    tcpClient.connectToHost(address, port);
    return true;
}
