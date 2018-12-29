#ifndef FORM_CREAT_CATEGORY_H
#define FORM_CREAT_CATEGORY_H

#include <QWidget>

namespace Ui {
class FormCreatCategory;
}

class FormCreatCategory : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreatCategory(QWidget *parent = 0);
    ~FormCreatCategory();

private:
    Ui::FormCreatCategory *ui;
};

#endif // FORM_CREAT_CATEGORY_H
