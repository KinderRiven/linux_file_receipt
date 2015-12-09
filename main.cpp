#include "mainwindow.h"
#include <QApplication>
#include "crecvserver.h"
#include "csendclient.h"
#include "headfile.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
