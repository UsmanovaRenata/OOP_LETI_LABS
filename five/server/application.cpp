#include "application.h"

Application::Application(int argc, char *argv[]) : QCoreApplication(argc, argv)
{
    CommParams pars = { QHostAddress("127.0.0.1"), 10000,
                             QHostAddress("127.0.0.1"), 10001};
    comm = new Communicator(pars, this);

    connect(comm, &Communicator::recieved, this, &Application::onRecieveFromClient);
}


void Application::onRecieveFromClient(QByteArray msg)
{

   auto splited = QString(msg).split(';');

   int matrixSize = splited[0].toInt();

   int index = 1;

   auto values = new number * [matrixSize];
       for (int i = 0; i < matrixSize; i++) {
           values[i] = new number[matrixSize];
       }

       for (int i = 0; i < matrixSize; i++) {

           for (int j = 0; j < matrixSize; j++) {

               QString text = splited[index];
               const QList<QString> textSplited = text.split('/');

               if (textSplited.length() > 1) {
                   values[i][j] = *(new number(textSplited[0].toInt(), textSplited[1].toInt()));
               } else {
                   values[i][j] = *(new number(textSplited[0].toInt()));
               }
                index++;

           }
       }

    SquareMatrix *m = new SquareMatrix(matrixSize, values);

    auto rank = m->rank();
    auto det = m->determinant();

    QString rankStr = QString::fromStdString(std::to_string(rank));
    QString detStr = QString::fromStdString(std::to_string(det.numerator) + '/' + std::to_string(det.denominator));

    QString res = rankStr + ';' + detStr;

   comm->sendTheDatagram(res.toUtf8());
}
