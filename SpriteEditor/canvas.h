#ifndef CANVAS_H
#define CANVAS_H
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
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
        // Removing setPixel, since canvas doesn't set indiviudal pixels
        // void setPixel(int x, int y, QRgb rgb);
        /**
         * @brief setImage - Displays passed image in the scene
         * @param image - QImage that needs to be displayed in the scene
         */
        void setImage(QImage* image);

    private:
        QPixmap pixmap;
        QImage image;
        // Boolean for letting mouse events know when to start putting pixels in the set touchedPixels
        bool catchPixels;
        // Converts and returns (non-scaled) grid coords
        QPointF convertToPoint(QPointF scaledPos);
        // Updates pixmap based on image by scaling it appropriately
        void updatePixmap();
};

#endif // CANVAS_H
