#include "main_window.h"
#include "ui_main_window.h"
#include <QIcon>
#include "titlebar.h"
#include "sql_manager.h"
#include "form_creat_journal.h"
#include "form_remark.h"
#include "form_show_journal.h"
#include "sql_manager.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowIcon(QIcon(":/file/cropped--150x150.jpg"));
    TitleBar *titlebar = new TitleBar(this);
    Q_UNUSED(titlebar);
    SqlManager sql_manager;
    ui->lineEdit_out_year->setText(QString::number(
       sql_manager.GetSumValue(SqlManager::SumValue_YearOut)));
    ui->lineEdit_in_year->setText(QString::number(
       sql_manager.GetSumValue(SqlManager::SumValue_Yearin)));
    ui->lineEdit_out__month->setText(QString::number(
       sql_manager.GetSumValue(SqlManager::SumValue_MonthOut)));
    ui->lineEdit_in_month->setText(QString::number(
       sql_manager.GetSumValue(SqlManager::SumValue_Monthin)));
    ui->lineEdit_out_all->setText(QString::number(
       sql_manager.GetSumValue(SqlManager::SumValue_AllOut)));
    ui->lineEdit_in_all->setText(QString::number(
       sql_manager.GetSumValue(SqlManager::SumValue_Allin)));
    ui->lineEdit_cha_all->setText(QString::number(ui->lineEdit_in_all->
       text().toDouble()-ui->lineEdit_out_all->text().toDouble()));
    ui->lineEdit_cha_month->setText(QString::number(ui->lineEdit_in_month->
       text().toDouble()-ui->lineEdit_out__month->text().toDouble()));
    ui->lineEdit_cha_year->setText(QString::number(ui->lineEdit_in_year->
       text().toDouble()-ui->lineEdit_out_year->text().toDouble()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_new_journal_clicked() {
    FormCreatJournal w;
    w.exec();
}

void MainWindow::on_pushButton_show_auditing_clicked() {
    FormRemark w;
    w.exec();
}

void MainWindow::on_pushButton_show_journal_clicked() {
    FormShowJournal w;
    w.exec();
}
