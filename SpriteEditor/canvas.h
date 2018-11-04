#ifndef CANVAS_H
#define CANVAS_H
#include <QPixmap>
#include <QGraphicsScene>

class Canvas  : public QGraphicsScene
{
    Q_OBJECT

    public:
        Canvas(QObject *parent = 0);
        virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);


    private:
        QPixmap pixmap;
        QImage image;
        int sizeX;
        int sizeY;

    public slots:
        void setPixel(QPoint pos, QRgb rgb);
};

#endif // CANVAS_H
