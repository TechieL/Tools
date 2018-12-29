#ifndef FORM_SHOW_JOURNAL_H
#define FORM_SHOW_JOURNAL_H

#include <QDialog>

namespace Ui {
class FormShowJournal;
}
class QStandardItemModel;
class FormShowJournal : public QDialog
{
    Q_OBJECT

public:
    explicit FormShowJournal(QWidget *parent = 0);
    ~FormShowJournal();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FormShowJournal *ui;
    QStandardItemModel *model;
};

#endif // FORM_SHOW_JOURNAL_H
