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
   int mode = splited[0].toInt();
   int matrixSize = splited[1].toInt();
   int index = 2;

   if(mode == C_MODE){
       auto values = new Tcomplex * [matrixSize];
           for (int i = 0; i < matrixSize; i++) {
               values[i] = new Tcomplex[matrixSize];
           }

           for (int i = 0; i < matrixSize; i++) {

               for (int j = 0; j < matrixSize; j++) {

                   QString text = splited[index];
                   const QList<QString> textSplited = text.split("+i");
                   values[i][j] = *(new Tcomplex(textSplited[0].toDouble(), textSplited[1].toDouble()));
                    index++;

               }
           }

        SquareMatrix<Tcomplex> *m = new SquareMatrix<Tcomplex>(matrixSize, values);

        auto rank = m->rank();
        Tcomplex det = m->determinant();
        QString rankStr = QString::fromStdString(std::to_string(rank));
        QString detStr = QString::fromStdString(std::to_string(det.real) + "+i" + std::to_string(det.image));

        QString res = rankStr + ';' + detStr;

       comm->sendTheDatagram(res.toUtf8());
   }

   if(mode == D_MODE){
       auto values = new double * [matrixSize];
           for (int i = 0; i < matrixSize; i++) {
               values[i] = new double[matrixSize];
           }

           for (int i = 0; i < matrixSize; i++) {
               for (int j = 0; j < matrixSize; j++) {
                   QString text = splited[index];
                    values[i][j] = *(new double(text.toDouble()));
                    index++;
               }
           }

        SquareMatrix<double> *m = new SquareMatrix<double>(matrixSize, values);

        auto rank = m->rank();
        double det = m->determinant();
        QString rankStr = QString::fromStdString(std::to_string(rank));
        QString detStr = QString::fromStdString(std::to_string(det));

        QString res = rankStr + ';' + detStr;

       comm->sendTheDatagram(res.toUtf8());
   }
   if(mode == R_MODE){
       auto values = new Rational * [matrixSize];
             for (int i = 0; i < matrixSize; i++) {
                 values[i] = new Rational[matrixSize];
             }

             for (int i = 0; i < matrixSize; i++) {

                 for (int j = 0; j < matrixSize; j++) {

                     QString text = splited[index];
                     const QList<QString> textSplited = text.split('/');

                     if (textSplited.length() > 1) {
                         values[i][j] = *(new Rational(textSplited[0].toInt(), textSplited[1].toInt()));
                     } else {
                         values[i][j] = *(new Rational(textSplited[0].toInt()));
                     }
                      index++;

                 }
             }

          SquareMatrix<Rational> *m = new SquareMatrix<Rational>(matrixSize, values);

          auto rank = m->rank();
          Rational det = m->determinant();
          det.nod();
          QString rankStr = QString::fromStdString(std::to_string(rank));
          QString detStr = QString::fromStdString(std::to_string(det.numerator) + '/' + std::to_string(det.denominator));

          QString res = rankStr + ';' + detStr;

         comm->sendTheDatagram(res.toUtf8());
   }
}
