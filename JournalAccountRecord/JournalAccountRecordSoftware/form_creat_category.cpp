#include "form_creat_category.h"
#include "ui_form_creat_category.h"

FormCreatCategory::FormCreatCategory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreatCategory)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/file/cropped--150x150.jpg"));
}

FormCreatCategory::~FormCreatCategory()
{
    delete ui;
}
