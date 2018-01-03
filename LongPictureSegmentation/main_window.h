#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <QMainWindow>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void SegmentationPostion(QPoint point);
    void on_pbt_open_clicked();
    void on_pbt_seg_clicked();
    void on_pbt_help_clicked();
    void on_pbt_clear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAIN_WINDOW_H
