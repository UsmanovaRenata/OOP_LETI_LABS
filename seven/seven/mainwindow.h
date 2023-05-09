#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include<QFileDialog>
#include<QMessageBox>
#include "orientedgraph.h"
#include "graphwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_check_path_clicked();

    void on_ok_clicked();

private:
    Ui::MainWindow *ui;
    GraphWindow *paint_graph;
};

#endif // MAINWINDOW_H
