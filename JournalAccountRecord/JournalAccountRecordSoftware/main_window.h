#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_new_journal_clicked();

    void on_pushButton_show_auditing_clicked();

    void on_pushButton_show_journal_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAIN_WINDOW_H
