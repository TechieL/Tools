#ifndef FORM_SHOW_CATEGORY_H
#define FORM_SHOW_CATEGORY_H

#include <QWidget>

namespace Ui {
class FormShowCategory;
}

class FormShowCategory : public QWidget
{
    Q_OBJECT

public:
    explicit FormShowCategory(QWidget *parent = 0);
    ~FormShowCategory();

private:
    Ui::FormShowCategory *ui;
};

#endif // FORM_SHOW_CATEGORY_H
