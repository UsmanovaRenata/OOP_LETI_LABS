#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->matrixSize = 2;
    resizeMatrixTable();

    connect(ui->updateButton,SIGNAL(pressed()),
            this,SLOT(formRequest()));
}

void MainWindow::formRequest()
{
    QString msg = QString::fromStdString(std::to_string(matrixSize));

    for (int i = 0; i < this->matrixWidgets.length(); i++) {\
        QLineEdit *line = matrixWidgets[i];
        msg += ";" + line->text();
    }

    emit requestToServer(msg);
}

void MainWindow::onResponseFromServer(QString msg)
{
    auto splited = msg.split(';');

    ui->rankValue->setText(splited[0]);
    ui->delimiterValue->setText(splited[1]);
}


void MainWindow::resizeMatrixTable() {
    if (this->matrixWidgets.length() > 0) {
        for (int i = 0; i < this->matrixWidgets.length(); i++) {
           ui->matrixGrid->removeWidget(this->matrixWidgets[i]);
        }
    }

    this->matrixWidgets.clear();


    for (int i = 0; i < this->matrixSize; i++) {
        QHBoxLayout *b = new QHBoxLayout();

        for (int j = 0; j < this->matrixSize; j++) {
            QLineEdit *widget = new QLineEdit();
            this->matrixWidgets.push_back(widget);
            b->addWidget(widget);
        }

        ui->matrixGrid->addLayout(b, i, 1);
    }

    ui->matrixSizeSpinBox->setValue(this->matrixSize);
}


void MainWindow::on_matrixSizeButton_clicked() {
    this->matrixSize = ui->matrixSizeSpinBox->value();
    ui->matrixSizeSpinBox->setValue(this->matrixSize);
    resizeMatrixTable();
}


MainWindow::~MainWindow()
{
    delete ui;
}

