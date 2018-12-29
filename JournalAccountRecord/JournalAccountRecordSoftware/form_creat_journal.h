#ifndef FORM_CREAT_JOURNAL_H
#define FORM_CREAT_JOURNAL_H

#include <QDialog>

namespace Ui {
class FormCreatJournal;
}

class FormCreatJournal : public QDialog
{
    Q_OBJECT

public:
    explicit FormCreatJournal(QWidget *parent = 0);
    ~FormCreatJournal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormCreatJournal *ui;
};

#endif // FORM_CREAT_JOURNAL_H
