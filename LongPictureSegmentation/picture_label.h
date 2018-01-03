#ifndef PICTURE_LABEL_H
#define PICTURE_LABEL_H
#include <QLabel>
class PictureLabel : public QLabel {
    Q_OBJECT
public:
    explicit PictureLabel(QWidget *parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags());
signals:
    void SegmentationPostion(QPoint);
protected:
    void mousePressEvent(QMouseEvent *ev) Q_DECL_FINAL;
};

#endif // PICTURE_LABEL_H
