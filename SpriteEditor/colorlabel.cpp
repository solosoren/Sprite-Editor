#include "colorlabel.h"
#include <QDebug>
#include <QColorDialog>

ColorLabel::ColorLabel(QWidget* parent):
    QLabel (parent)
{

}

void ColorLabel::mousePressEvent(QMouseEvent* ev) {
    qInfo() << "Clicked label";
    QColor color = QColorDialog::getColor();
    emit colorChanged(color);
}
