#include "main_window.h"
#include "ui_main_window.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
namespace techieliang {
namespace tools {
namespace source_file_collection_private {
/**
 * @brief 遍历文件夹得到所有文件路径
 * @param dir_Path 文件夹路径
 * @return 文件夹内所有文件的绝对路径，不包括文件夹名称
 */
QList<QFileInfo> ErgodicDirectoryToFilePath(QString dir_Path) {
    QDir dir(dir_Path);
    QList<QFileInfo> files_path;
    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::NoSymLinks);
    QFileInfoList folders = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(QFileInfo folder : folders)
        files_path.append(ErgodicDirectoryToFilePath(folder.filePath()));
    files_path.append(files);
    return files_path;
}
}//namespace source_file_collection_private
}//namespace tools
}//namespace techieliang
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_get_directory_clicked() {
    directory_ = QFileDialog::getExistingDirectory(this);
    qDebug()<<directory_;
}

void MainWindow::on_pushButton_collection_clicked() {
    QDir md(directory_);
    if(directory_.isEmpty() || !md.exists()) {
        QMessageBox::information(this, "注意", "请先选择路径", QMessageBox::Ok);
        return;
    }
    QList<QFileInfo> files_path;
    files_path = techieliang::tools::source_file_collection_private::ErgodicDirectoryToFilePath(directory_);
    QFile write_file("collection_result.txt");
    if(!write_file.open(QFile::WriteOnly)) {
        QMessageBox::information(this, "注意", "存储目标文件打开失败", QMessageBox::Ok);
        return;
    }
    QTextStream ws(&write_file);
    for(auto file_path : files_path) {
        QFile read_file(file_path.filePath());
        if(!read_file.open(QFile::ReadOnly)) {
            QMessageBox::information(this, "注意", file_path.filePath()+"\r\n文件打开失败，未整理到文件", QMessageBox::Ok);
        }
        QTextStream rs(&read_file);
        ws<<file_path.fileName()<<"\r\n";
        ws<<rs.readAll()<<"\r\n";
        read_file.close();
    }
    write_file.close();
    QMessageBox::information(this, "完成", "整理完成", QMessageBox::Ok);
}
