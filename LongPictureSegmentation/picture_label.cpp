#include "picture_label.h"

#include <QMouseEvent>

PictureLabel::PictureLabel(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent, f) {

}

void PictureLabel::mousePressEvent(QMouseEvent *ev) {
    if(ev->button() == Qt::RightButton) {
        emit SegmentationPostion(ev->pos());
    }
    QLabel::mousePressEvent(ev);
}
