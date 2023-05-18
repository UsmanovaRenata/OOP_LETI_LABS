#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "area.h"
#include "parametersdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class Area;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_reset_clicked();

    void on_move_clicked();

    void on_change_parametrs_clicked();

private:
    Ui::MainWindow *ui;
    Area *area_widget;
    bool isReset;
    ParametersDialog *dialog;

};
#endif // MAINWINDOW_H
