#include <QCoreApplication>
#include "MyTcpServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;
    if (server.startServer()) {
        qDebug() << "Server started!";
    } else {
        qDebug() << "Server could not start!";
    }

    return a.exec();
}
