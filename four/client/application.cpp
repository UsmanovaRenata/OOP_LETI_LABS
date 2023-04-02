#include "application.h"



Application::Application(int argc, char *argv[])
   : QApplication(argc,argv)
{

    CommParams pars = { QHostAddress("127.0.0.1"), 10001,
                             QHostAddress("127.0.0.1"), 10000};

    comm = new Communicator(pars, this);
    mw = new MainWindow();
    mw->show();

    connect(comm, &Communicator::recieved, this, &Application::onRecieveFromServer);
    connect(mw, &MainWindow::requestToServer, this, &Application::onSendToServer);
}


void Application::onRecieveFromServer(QByteArray msg)
{
    mw->onResponseFromServer(QString(msg));
}

void Application::onSendToServer(QString msg)
{
    QByteArray qbytemsg = msg.toUtf8();
    comm->sendTheDatagram(qbytemsg);
}
