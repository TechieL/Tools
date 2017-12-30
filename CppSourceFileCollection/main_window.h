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
    void on_pushButton_get_directory_clicked();

    void on_pushButton_collection_clicked();

private:
    Ui::MainWindow *ui;
    QString directory_{""};
};

#endif // MAIN_WINDOW_H
