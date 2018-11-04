#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#ifndef FRAMECONTROLLER_H
#define FRAMECONTROLLER_H


class FrameController : public QGraphicsScene
{
    Q_OBJECT
    using QGraphicsScene::QGraphicsScene; //constructor inheritance

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
    void pixelClicked(QPoint pos, QRgb rgb);
};

#endif // FRAMECONTROLLER_H
