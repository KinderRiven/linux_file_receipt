#ifndef RECVFILESERVER_H
#define RECVFILESERVER_H
#include "headfile.h"

class recvFileServer : public QWidget
{
    //Q_OBJECT

public:
    recvFileServer(QWidget *parent = NULL);
    ~recvFileServer();
    bool start();
private:
    QTcpServer tcpServer;
    bool DEBUG;
    int port;
private slots:
    void newConnectionSlot();
};

#endif // RECVFILESERVER_H
