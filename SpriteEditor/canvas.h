#ifndef CANVAS_H
#define CANVAS_H
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "global.h"

using namespace GLOBAL;

class Canvas  : public QGraphicsScene
{
    Q_OBJECT

    public:
        Canvas(QObject *parent = 0);

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
        QImage* getImage();

        /**
         * @brief makeNewEmptyImage - Makes new empty QImage and updates the scene with it
         * @return - Pointer to newly made QImage
         */
        QImage* makeNewEmptyImage();

    signals:
        void mousePressed(QPointF point);
        void mouseMoved(QPointF point);
        void mouseReleased(QPointF point);

    public slots:

    private:
        QPixmap pixmap;
        QImage* image;
        // Converts and returns (non-scaled) grid coords
        QPointF convertToPoint(QPointF scaledPos);
        // Updates pixmap based on image by scaling it appropriately
        void updatePixmap();
};

#endif // CANVAS_H
