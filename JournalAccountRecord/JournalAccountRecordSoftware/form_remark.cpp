#include "form_remark.h"
#include "ui_form_remark.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include "sql_manager.h"
FormRemark::FormRemark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormRemark)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/file/cropped--150x150.jpg"));
    QStandardItemModel *model = new QStandardItemModel;
    ui->treeView->setModel(model);
    int num=0;
    model->setHorizontalHeaderItem(num++,new QStandardItem("ID"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("分类"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("日期"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("记录"));
    model->setHorizontalHeaderItem(num++,new QStandardItem("备注"));
    SqlManager m;
    auto jours = m.SelectUnauditJournalSql(false);
    QList<QStandardItem *> item_list;
    QStandardItem *item;
    for(auto jour : jours) {
        item_list.clear();
        item=new QStandardItem();
        item->setData(jour.id, Qt::EditRole);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.catagory, Qt::EditRole);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.date, Qt::EditRole);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.value, Qt::EditRole);
        item_list.append(item);
        item=new QStandardItem();
        item->setData(jour.remark, Qt::EditRole);
        item_list.append(item);
        model->appendRow(item_list);
    }
}

FormRemark::~FormRemark()
{
    delete ui;
}
void FormRemark::on_pushButton_clicked() {
    auto index = ui->treeView->currentIndex();
    auto model = (QStandardItemModel *)(ui->treeView->model());
    auto current_item = model->itemFromIndex(index);
    auto id =model->item(current_item->row(),0)->text();
    auto r = QMessageBox::warning(this,
                         "确认审核通过",
                         "确认审核通过id="+id,
                         QMessageBox::Yes,
                         QMessageBox::No);
    if(r==QMessageBox::Yes) {
        SqlManager m;
        if(m.UpdateAuditJournalSql(id.toLongLong()))
            model->removeRow(current_item->row());
    }

}

void FormRemark::on_pushButton_2_clicked() {
    auto index = ui->treeView->currentIndex();
    auto model = (QStandardItemModel *)(ui->treeView->model());
    auto current_item = model->itemFromIndex(index);
    auto id =model->item(current_item->row(),0)->text();
    auto r = QMessageBox::warning(this,
                         "确认删除",
                         "确认删除id="+id,
                         QMessageBox::Yes,
                         QMessageBox::No);
    if(r==QMessageBox::Yes) {
        SqlManager m;
        if(m.DeleteJournal(id.toLongLong()))
            model->removeRow(current_item->row());
    }
}
