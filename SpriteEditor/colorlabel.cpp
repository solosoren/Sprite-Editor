#include "colorlabel.h"
#include <QDebug>
#include <QColorDialog>

ColorLabel::ColorLabel(QWidget* parent):
    QLabel (parent)
{

}

void ColorLabel::mousePressEvent(QMouseEvent* ev) {
    qInfo() << "Clicked label";
    QColorDialog colorDialog;
    QColor color = colorDialog.getColor();
    if(color != QColor::Invalid) {
        emit colorChanged(color);
    }
}
