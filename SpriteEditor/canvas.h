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
        Canvas(int frameSizeX, int frameSizeY, QImage* image, QObject *parent = 0);

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
        void mousePressed(int button, QPointF point);
        void mouseMoved(int button, QPointF point);
        void mouseReleased(int button, QPointF point);

    public slots:

    private:
        QPixmap pixmap;
        QImage* image;
        bool enableDebugging;
        bool enableGridLines;
        int framePixelSizeX;
        int framePixelSizeY;
        // Converts and returns (non-scaled) grid coords
        QPointF convertToPoint(QPointF scaledPos);
        // Updates pixmap based on image by scaling it appropriately
        void updatePixmap();
        void pointDebugMessage(QString message, QPointF point);
};

#endif // CANVAS_H
