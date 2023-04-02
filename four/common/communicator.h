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
//    void processTheDatagram(QNetworkDatagram datagram);

signals:
    void response(QByteArray msg);
    void request(QByteArray msg);
    void recieved(QByteArray msg);

public slots:
    void readPendingDatagrams();
    void sendTheDatagram(QByteArray);

private:
    CommParams params;

    bool ready;
};

#endif // COMMUNICATOR_H
