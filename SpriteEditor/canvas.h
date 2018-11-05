#ifndef CANVAS_H
#define CANVAS_H
#include <QPixmap>
#include <QGraphicsScene>
#include "mainwindow.h"

using namespace GLOBAL;

class Canvas  : public QGraphicsScene
{
    Q_OBJECT

    public:
        Canvas(QObject *parent = 0);
        virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
        void setPixel(int x, int y, QRgb rgb);

    private:
        QPixmap pixmap;
        QImage image;
        // boolean for letting mouse events know when to start putting pixels in the set touchedPixels
        bool catchPixels;
        // Converts and returns (non-scaled) grid coords
        QPointF convertToPoint(QPointF scaledPos);
        // Updates pixmap based on image
        void updatePixmap();
};

#endif // CANVAS_H
