#include "framecontroller.h"
#include <QDebug>

void FrameController::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        qInfo() << "int mousePRess event: " << event->buttonDownPos(Qt::LeftButton);
        emit pixelClicked(event->pos().toPoint(), qRgb(0,0,0));
    }
    QGraphicsScene::mousePressEvent(event);
}
