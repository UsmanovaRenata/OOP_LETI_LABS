#ifndef PARAMETERSDIALOG_H
#define PARAMETERSDIALOG_H

#include <QDialog>

namespace Ui {
class ParametersDialog;
}

class ParametersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParametersDialog(QWidget *parent = nullptr);
    ~ParametersDialog();
    qreal getR();
    qreal getV();
    qreal getA();
private:
    Ui::ParametersDialog *ui;

};

#endif // PARAMETERSDIALOG_H
