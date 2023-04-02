#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QObject>

#include "communicator.h"
#include "mainwindow.h"

class Application : public QApplication
{
    Q_OBJECT

    Communicator *comm;
    MainWindow *mw;
    QUdpSocket *udpSocket;

signals:
    void sendServer(QString);
private slots:
    void onRecieveFromServer(QByteArray msg);
    void onSendToServer(QString);
public:
    Application(int, char**);
};

#endif // APPLICATION_H
