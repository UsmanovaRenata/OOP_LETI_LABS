#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

struct CommParams
{
    QHostAddress rHost;
    quint16      rPort;
    QHostAddress sHost;
    quint16      sPort;
};

class Communicator : public QUdpSocket
{
    Q_OBJECT

    QUdpSocket *udpSocket;

public:
    Communicator(CommParams &pars, QObject *parent);

signals:
    void recieved(QByteArray msg);

public slots:
    void readPendingDatagrams();
    void sendTheDatagram(QByteArray);

private:
    CommParams params;

    bool ready;
};

#endif // COMMUNICATOR_H
