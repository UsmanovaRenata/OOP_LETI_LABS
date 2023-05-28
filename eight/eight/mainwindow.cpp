#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),paint_graph(nullptr)
{
    ui->setupUi(this);
    ui->lineEdit->setText("1");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete paint_graph;
}

void MainWindow::on_check_path_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),tr(""),tr("*.txt"));
    ui->path->setText(fileName);
}


void MainWindow::on_ok_clicked()
{

    QFile file(ui->path->text());
    QFileInfo check_file(ui->path->text());
    if (check_file.exists() && check_file.isFile() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {


         QByteArray content = file.readAll();
         StateGraph graph(content, (ui->lineEdit->text()).toInt());
         if(graph.m->matrix.size() != graph.m->matrix[0].size()){
             QMessageBox messageBox;
             messageBox.critical(0,"Error","Ошибка размерности матрицы");
             messageBox.setFixedSize(500,200);
         }else{
         paint_graph = new GraphWindow(graph);
         paint_graph->show();
         }
        }
    else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Ошибка чтения файла");
        messageBox.setFixedSize(500,200);
        }

}


void MainWindow::on_pushButton_2_clicked()
{
    if(paint_graph != nullptr){
    int eventNumber = QInputDialog::getInt(this, tr("Новое событие"), tr("Введите номер события:"));
    int newNode = paint_graph->get_event(eventNumber);
    if(newNode > 0){
        ui->lineEdit->setText(QString::number(newNode));
    }
    }else{
        QMessageBox::warning(this, tr("Ошибка"), tr("Граф не построен"), QMessageBox::Ok);
    }
}


void MainWindow::on_pushButton_clicked()
{
    if(paint_graph != nullptr){
    paint_graph->get_active((ui->lineEdit->text()).toInt());
    }else{
        QMessageBox::warning(this, tr("Ошибка"), tr("Граф не построен"), QMessageBox::Ok);
    }
}

