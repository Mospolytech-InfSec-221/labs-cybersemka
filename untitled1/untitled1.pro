QT += network

CONFIG += c++11

TARGET = MyTcpServer
TEMPLATE = app

SOURCES += \
    main.cpp \
    MyTcpServer.cpp

HEADERS += \
    MyTcpServer.h

DESTDIR = $$PWD/build
