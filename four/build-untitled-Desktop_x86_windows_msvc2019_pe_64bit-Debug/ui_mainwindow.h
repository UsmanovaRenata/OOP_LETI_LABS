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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *matrixSizeButton;
    QLabel *label;
    QSpinBox *matrixSizeSpinBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *delimiterValue;
    QLabel *rankValue;
    QLabel *label_3;
    QPushButton *updateButton;
    QWidget *gridLayoutWidget_3;
    QGridLayout *matrixGrid;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *d_mode;
    QRadioButton *c_mode;
    QRadioButton *r_mode;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 268, 58));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        matrixSizeButton = new QPushButton(gridLayoutWidget);
        matrixSizeButton->setObjectName(QString::fromUtf8("matrixSizeButton"));

        gridLayout->addWidget(matrixSizeButton, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        matrixSizeSpinBox = new QSpinBox(gridLayoutWidget);
        matrixSizeSpinBox->setObjectName(QString::fromUtf8("matrixSizeSpinBox"));
        matrixSizeSpinBox->setMaximum(1000);

        gridLayout->addWidget(matrixSizeSpinBox, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 6);
        gridLayout->setRowStretch(1, 4);
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(540, 70, 221, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        delimiterValue = new QLabel(gridLayoutWidget_2);
        delimiterValue->setObjectName(QString::fromUtf8("delimiterValue"));

        gridLayout_2->addWidget(delimiterValue, 2, 2, 1, 1);

        rankValue = new QLabel(gridLayoutWidget_2);
        rankValue->setObjectName(QString::fromUtf8("rankValue"));

        gridLayout_2->addWidget(rankValue, 1, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        updateButton = new QPushButton(gridLayoutWidget_2);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        gridLayout_2->addWidget(updateButton, 0, 2, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 70, 511, 481));
        matrixGrid = new QGridLayout(gridLayoutWidget_3);
        matrixGrid->setObjectName(QString::fromUtf8("matrixGrid"));
        matrixGrid->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 10, 201, 20));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(300, 40, 406, 28));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        d_mode = new QRadioButton(widget);
        d_mode->setObjectName(QString::fromUtf8("d_mode"));
        d_mode->setChecked(true);

        horizontalLayout->addWidget(d_mode);

        c_mode = new QRadioButton(widget);
        c_mode->setObjectName(QString::fromUtf8("c_mode"));

        horizontalLayout->addWidget(c_mode);

        r_mode = new QRadioButton(widget);
        r_mode->setObjectName(QString::fromUtf8("r_mode"));

        horizontalLayout->addWidget(r_mode);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        matrixSizeButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \320\274\320\260\321\202\321\200\320\270\321\206\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\321\200\320\265\320\264\320\265\320\273\320\270\321\202\320\265\320\273\321\214 ", nullptr));
        delimiterValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        rankValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\275\320\263", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        d_mode->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\260\321\217", nullptr));
        c_mode->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\273\320\265\320\272\321\201\320\275\320\260\321\217", nullptr));
        r_mode->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
