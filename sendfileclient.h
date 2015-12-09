#ifndef SENDFILECLIENT_H
#define SENDFILECLIENT_H

#include "headfile.h"

class sendFileClient : public QWidget
{
    //Q_OBJECT

public:
    sendFileClient(QWidget *parent = NULL);
    ~sendFileClient();
    bool startConnect();

private:
    QHostAddress address;
    QTcpSocket tcpClient;
    QString ipAddress;
    int port;
    bool DEBUG;
};

#endif // SENDFILECLIENT_H
