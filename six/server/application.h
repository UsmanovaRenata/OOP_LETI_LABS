#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include "squarematrix.h"
#include "communicator.h"
#include "common.h"
#include "complex.h"
#include "rational.h"


class Application : public QCoreApplication
{
    Q_OBJECT

    Communicator *comm;



public slots:
    void onRecieveFromClient(QByteArray msg);
public:
    Application(int, char **);
};

#endif // APPLICATION_H
