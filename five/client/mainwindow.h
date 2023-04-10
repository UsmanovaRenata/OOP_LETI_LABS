#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "communicator.h"
#include "qlineedit.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int matrixSize;
    QList<QLineEdit *> matrixWidgets;
    Communicator *comn;
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    void onResponseFromServer(QString msg);

private slots:
    void on_matrixSizeButton_clicked();
    void formRequest();


signals:
    void requestToServer(QString);

private:
    void resizeMatrixTable();


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
