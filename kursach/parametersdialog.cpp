#include "parametersdialog.h"
#include "ui_parametersdialog.h"

ParametersDialog::ParametersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParametersDialog)
{
    ui->setupUi(this);
    ui->R->setValue(25);
    ui->V->setValue(20);
    ui->A->setValue(45);
    ui->A->setRange(0, 180);
}

ParametersDialog::~ParametersDialog()
{
    delete ui;
}

qreal ParametersDialog::getR()
{
    return ui->R->value();
}

qreal ParametersDialog::getV()
{
    return ui->V->value();
}

qreal ParametersDialog::getA()
{
    return ui->A->value();
}
