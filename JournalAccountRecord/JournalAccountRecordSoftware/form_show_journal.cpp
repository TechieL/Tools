#include "form_show_journal.h"
#include "ui_form_show_journal.h"
#include <QStandardItemModel>
#include <QDate>
#include <QDebug>
#include "sql_manager.h"
FormShowJournal::FormShowJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormShowJournal)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/file/cropped--150x150.jpg"));
    model = new QStandardItemModel;
    int year = QDate::currentDate().year();
    while (year>1900)
        ui->comboBox_year->addItem(QString::number(year--));
    ui->treeView->setModel(model);
    int num=0;
    model->setHorizontalHeaderItem(num++,new QStandardItem("ID"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("日期"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("分类"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("记录"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("备注"));
}

FormShowJournal::~FormShowJournal()
{
    delete ui;
}

void FormShowJournal::on_pushButton_2_clicked() {
    model->removeRows(0,model->rowCount());
    SqlManager m;
    auto jours = m.SelectUnauditJournalSql(true);
    QList<QStandardItem *> item_list;
    QStandardItem *item;
    for(auto jour : jours) {
        item_list.clear();
        item=new QStandardItem();
        item->setData(jour.id, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.date, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.catagory, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.value, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.remark, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        model->appendRow(item_list);
    }
    ui->treeView->setColumnWidth(0,70);
    ui->treeView->setColumnWidth(1,100);
    ui->treeView->setColumnWidth(2,50);
    ui->treeView->setColumnWidth(3,80);
}

void FormShowJournal::on_pushButton_clicked() {
    model->removeRows(0,model->rowCount());
    SqlManager m;
    QList<JournalStruct> jours;
    if(ui->comboBox_month->currentText()=="全部") {
        QString date = ui->comboBox_year->currentText();
        jours = m.SelectMonthJournalSql(QDate::
          fromString(date,"yyyy"),
          SqlManager::DataType_Year);

    }
    else {
        QString date = ui->comboBox_year->currentText();
        date+="-"+ui->comboBox_month->currentText();
        jours = m.SelectMonthJournalSql(
          QDate::fromString(date,"yyyy-M"),
          SqlManager::DataType_Month);
    }
    QList<QStandardItem *> item_list;
    QStandardItem *item;
    for(auto jour : jours) {
        item_list.clear();
        item=new QStandardItem();
        item->setData(jour.id, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.date, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.catagory, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.value, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.remark, Qt::EditRole);
        item->setEditable(false);
        item_list.append(item);
        model->appendRow(item_list);
    }
    ui->treeView->setColumnWidth(0,70);
    ui->treeView->setColumnWidth(1,100);
    ui->treeView->setColumnWidth(2,50);
    ui->treeView->setColumnWidth(3,80);
}
