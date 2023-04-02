#include "communicator.h"
#include <QNetworkDatagram>

Communicator::Communicator(CommParams &pars, QObject *parent) : QUdpSocket(parent)
{
    params = pars;
    ready = bind(params.rHost, params.rPort,
                    QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    if (ready) connect(this, &QUdpSocket::readyRead,
                       this, &Communicator::readPendingDatagrams);
}

void Communicator::readPendingDatagrams()
{
    if (hasPendingDatagrams())
    {
        quint64 size = pendingDatagramSize();
        QByteArray msg(size,'\0');
        readDatagram(msg.data(), size);
        //qDebug()<<"recieved"<<msg;
        emit recieved(msg);
    }
}

void Communicator::sendTheDatagram(QByteArray msg)
{
    if (ready)
    {
        writeDatagram(msg, params.sHost, params.sPort);
    }
}
