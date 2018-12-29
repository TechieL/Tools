#ifndef FORM_REMARK_H
#define FORM_REMARK_H

#include <QDialog>

namespace Ui {
class FormRemark;
}

class FormRemark : public QDialog
{
    Q_OBJECT

public:
    explicit FormRemark(QWidget *parent = 0);
    ~FormRemark();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormRemark *ui;
};

#endif // FORM_REMARK_H
