#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isReset = false;
    area_widget = new Area;
    ui->graphicsView->setFixedSize(area_widget->getL(), area_widget->getW());
    ui->graphicsView->setScene(area_widget->getScene());
    dialog = new ParametersDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete area_widget;
    delete dialog;
}


void MainWindow::on_reset_clicked()
{
    area_widget->reset();
    isReset = true;

}


void MainWindow::on_move_clicked()
{
    area_widget->keep_move();
    isReset = false;

}


void MainWindow::on_change_parametrs_clicked()
{
    if(isReset){

        dialog->show();
        if (dialog->exec() == QDialog::Accepted) {
               qreal newRadius = dialog->getR();
               qreal newSpeed = dialog->getV();
               qreal newAngle = dialog->getA();
               area_widget->updateBallParameters(newRadius, newSpeed, newAngle);
        }
    }
}

