#ifndef SENDCLIENT_H
#define SENDCLIENT_H

#include "headfile.h"

class sendClient : public QWidget
{
    Q_OBJECT

public:
    sendClient(QWidget *parent = NULL);
    ~sendClient();
    bool startConnect();

private:
    QHostAddress address;
    QTcpSocket tcpClient;
    QString ipAddress;
    int port;
    bool DEBUG;
};

#endif // SENDCLIENT_H
