#ifndef RECVSERVER_H
#define RECVSERVER_H

#include "headfile.h"

class recvServer : public QWidget
{
    Q_OBJECT

public:
    recvServer(QWidget *parent = NULL);
    ~recvServer();
    bool start();

private:
    QTcpServer tcpServer;
    bool DEBUG;
    int port;
private slots:
    void newConnectionSlot();

};

#endif // RECVSERVER_H
