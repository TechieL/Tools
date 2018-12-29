#include "form_show_category.h"
#include "ui_form_show_category.h"

FormShowCategory::FormShowCategory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormShowCategory)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/file/cropped--150x150.jpg"));
}

FormShowCategory::~FormShowCategory()
{
    delete ui;
}
