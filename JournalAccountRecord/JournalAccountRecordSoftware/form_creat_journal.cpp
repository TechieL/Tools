#include "form_creat_journal.h"
#include "ui_form_creat_journal.h"
#include <QDate>
#include "sql_manager.h"
FormCreatJournal::FormCreatJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormCreatJournal)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/file/cropped--150x150.jpg"));
    ui->dateEdit->setDate(QDate::currentDate());//当前日期
    ui->dateEdit->setCalendarPopup(true);//日历显示
    //限制金额只能为数字
    QDoubleValidator* adoubleValidator = new QDoubleValidator;
    ui->lineEdit->setValidator(adoubleValidator);
    //分类列表
    SqlManager m;
    auto categorys = m.SelectCategorySql();
    for(auto category : categorys)
        ui->comboBox->addItem(category.name, category.id);
}

FormCreatJournal::~FormCreatJournal() {
    delete ui;
}

void FormCreatJournal::on_pushButton_clicked() {
    if(ui->lineEdit->text().isEmpty())
        return;
    SqlManager m;
    bool r;
    r = m.InsertJournalSql(ui->comboBox->currentData().toInt(),
                       ui->dateEdit->date(),
                       ui->lineEdit->text().toFloat(),
                       ui->textEdit->toPlainText(),
                       ui->checkBox->isChecked());
    if(r)
        close();
}

void FormCreatJournal::on_pushButton_2_clicked() {
    close();
}
