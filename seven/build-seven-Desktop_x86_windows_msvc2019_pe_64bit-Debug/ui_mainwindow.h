/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLineEdit *path;
    QPushButton *ok;
    QPushButton *check_path;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(793, 153);
        path = new QLineEdit(MainWindow);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(140, 60, 601, 28));
        ok = new QPushButton(MainWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(660, 110, 83, 29));
        check_path = new QPushButton(MainWindow);
        check_path->setObjectName(QString::fromUtf8("check_path"));
        check_path->setGeometry(QRect(10, 60, 121, 29));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        path->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\277\321\203\321\202\321\214 \320\264\320\276 \321\204\320\260\320\271\320\273\320\260", nullptr));
        ok->setText(QCoreApplication::translate("MainWindow", "\320\236\320\232", nullptr));
        check_path->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
