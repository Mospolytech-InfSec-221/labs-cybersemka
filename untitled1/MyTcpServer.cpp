#include "MyTcpServer.h"
#include <QDebug>
#include <QRandomGenerator>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    // Здесь вы можете добавить зарегистрированных пользователей по умолчанию, если это необходимо
    // registeredUsers.insert("user1", "password1");
}

bool MyTcpServer::startServer()
{
    return server->listen(QHostAddress::Any, 12345);
}

void MyTcpServer::onNewConnection()
{
    if (sockets.size() >= 4) {
        qDebug() << "Cannot accept more than 4 clients. Connection limit reached.";
        return;
    }

    QTcpSocket *socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    sockets.append(socket);
    qDebug() << "Client connected, descriptor: " << socket->socketDescriptor();
}

void MyTcpServer::onReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    QString message = QString(data).trimmed();
    qDebug() << "Received message from client: " << message;

    QStringList parts = message.split(";");
    if (parts.size() >= 3) {
        if (parts[0] == "auth") {
            QString login = parts[1];
            QString password = parts[2];

            if (parts.size() == 4) {
                int codenumber = parts[3].toInt();
                // Проверка кода проверки (codenumber) - произвольное число, каждый раз разное
                // В данном случае просто проверяем, что codenumber - это случайное число от 1000 до 9999
                if (codenumber >= 1000 && codenumber <= 9999) {
                    // Авторизация прошла успешно
                    socket->setProperty("loggedin", true);
                    socket->write(QString("code:%1").arg(codenumber).toUtf8());
                    qDebug() << "User logged in with codenumber: " << codenumber;
                    return;
                } else {
                    // Неверный код проверки
                    socket->write("auth-;Invalid verification code.");
                    qDebug() << "Authentication failed for user: " << login;
                    return;
                }
            }

            // Проверка логина и пароля
            if (registeredUsers.contains(login) && registeredUsers.value(login) == password) {
                socket->setProperty("loggedin", true);
                socket->write("auth+;You are now logged in.");
                qDebug() << "User logged in: " << login;
            } else {
                socket->write("auth-;Authentication failed.");
                qDebug() << "Authentication failed for user: " << login;
            }
        } else if (parts[0] == "reg") {
            QString login = parts[1];
            QString password = parts[2];

            if (!registeredUsers.contains(login)) {
                registeredUsers.insert(login, password);
                socket->write("reg+;Registration successful.");
                qDebug() << "User registered: " << login;
            } else {
                socket->write("reg-;User with this login already exists.");
                qDebug() << "Registration failed for user: " << login;
            }
        } else {
            // Неправильный формат запроса
            socket->write("Invalid format;Invalid request format.");
            qDebug() << "Invalid request format from client.";
        }
    } else {
        // Неправильный формат запроса
        socket->write("Invalid format;Invalid request format.");
        qDebug() << "Invalid request format from client.";
    }
}

void MyTcpServer::onDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    sockets.removeOne(socket);
    socket->deleteLater();
    qDebug() << "Client disconnected, descriptor: " << socket->socketDescriptor();
}
