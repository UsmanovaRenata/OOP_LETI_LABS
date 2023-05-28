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
#include <QtWidgets/QLabel>
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
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(755, 171);
        path = new QLineEdit(MainWindow);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(140, 60, 601, 28));
        ok = new QPushButton(MainWindow);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(580, 130, 171, 29));
        check_path = new QPushButton(MainWindow);
        check_path->setObjectName(QString::fromUtf8("check_path"));
        check_path->setGeometry(QRect(10, 60, 121, 29));
        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 130, 151, 29));
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 141, 20));
        lineEdit = new QLineEdit(MainWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 130, 113, 28));
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 130, 151, 29));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        path->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\277\321\203\321\202\321\214 \320\264\320\276 \321\204\320\260\320\271\320\273\320\260", nullptr));
        ok->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        check_path->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\276\320\265 \321\201\320\276\320\261\321\213\321\202\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\220\320\272\321\202\320\270\320\262\320\275\320\260\321\217 \320\262\320\265\321\200\321\210\320\270\320\275\320\260:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\262\320\265\321\200\321\210\320\270\320\275\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
