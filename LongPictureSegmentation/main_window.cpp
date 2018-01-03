#include "main_window.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QListWidget>
#include <QLabel>
#include "picture_label.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pictureLabel,
            &PictureLabel::SegmentationPostion,
            this,
            &MainWindow::SegmentationPostion);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SegmentationPostion(QPoint point) {
    ui->listWidget->addItem(QString::number(point.y()));
}

void MainWindow::on_pbt_open_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this,
                                                     tr("选择图像"),
                                                     "",
                                                     tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(file_name.isEmpty())
        return;
    QImage image;
    if(!image.load(file_name))
        QMessageBox::about(this, "加载失败", "图片加载失败");
    ui->pictureLabel->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pbt_seg_clicked() {
    if(ui->listWidget->count() == 0) {
        QMessageBox::about(this, "请选择", "请选择分割线，若无任何分割线则程序不会工作");
        return;
    }
    if(ui->pictureLabel->pixmap() == nullptr) {
        QMessageBox::about(this, "错误", "请先打开图片");
        return;
    }
    if(ui->pictureLabel->pixmap()->isNull()) {
        QMessageBox::about(this, "错误", "请先打开图片");
        return;
    }
    QString save_path = QFileDialog::
            getExistingDirectory(this, tr("保存路径"));
    if(save_path.isEmpty()) {
        QMessageBox::about(this, "错误", "未选择保存路径");
        return;
    }
    QList<int> pos_list;
    for(int i = 0, num = ui->listWidget->count(); i < num; ++i) {
        pos_list.append(ui->listWidget->item(i)->text().toInt());
    }
    auto source_image =ui->pictureLabel->pixmap()->toImage();
    std::sort(pos_list.begin(), pos_list.end());
    for(int i = 0, num = pos_list.size(); i < num; ++i) {
        QImage save_image;
        if(i == 0) {
            Q_ASSERT(pos_list[i] >= 0);
            save_image = source_image.copy(0,
                    0,
                    source_image.width(),
                    pos_list[i]);
        }
        else if(i > 0) {
            Q_ASSERT(pos_list[i] >= pos_list[i-1]);
            save_image = source_image.copy(0,
                    pos_list[i-1],
                    source_image.width(),
                    pos_list[i] - pos_list[i-1]);
        }
        if(!save_image.save(save_path + "/LPS_save_" +
                            QString::number(i) + ".jpg"))
            QMessageBox::about(this, "保存失败", "图片保存失败");
    }
    QImage save_end_image = source_image.copy(0,
            pos_list[pos_list.size() - 1],
            source_image.width(),
            source_image.height() - pos_list[pos_list.size() - 1]);
    if(!save_end_image.save(save_path + "/LPS_save_" +
                            QString::number(pos_list.size()) + ".jpg"))
        QMessageBox::about(this, "保存失败", "图片保存失败");
}

void MainWindow::on_pbt_help_clicked() {
    QMessageBox::about(this, "帮助", "打开图片：选择要进行分割的图片\r\n分割线"
                                   "：图像中以那一行的位置作为分割，右键点击要"
                                   "分割的地方则会记录\r\n分割：点击分割按钮程"
                                   "序会要求选择要保存的文件路径，选择路径后保存");
}

void MainWindow::on_pbt_clear_clicked() {
    ui->listWidget->clear();
}
