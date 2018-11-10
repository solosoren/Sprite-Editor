#ifndef CANVAS_H
#define CANVAS_H

#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "global.h"


class Canvas  : public QGraphicsScene
{
    Q_OBJECT

    public:
        Canvas(QImage* image, QObject *parent = 0);

        /* Mouse events*/
        virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
        virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

        /**
         * @brief setImage - Displays passed image in the scene
         * @param image - QImage that needs to be displayed in the scene
         * @return - Pointer to QImage being displayed
         */
        void setImage(QImage* image);

        void toggleGridlines();

    signals:
        void mouseLeftPressed(QPointF point);
        void mouseRightPressed(QPointF point);
        void mouseMoved(QPointF point);
        void mouseReleased(QPointF point);

    public slots:

    private:
        QPixmap pixmap;
        QImage* image;
        bool enableDebugging;
        bool enableGridLines;
        // Converts and returns (non-scaled) grid coords
        QPointF convertToPoint(QPointF scaledPos);
        // Updates pixmap based on image by scaling it appropriately
        void updatePixmap();
        void pointDebugMessage(QString message, QPointF point);
};

#endif // CANVAS_H
