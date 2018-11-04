#include "canvas.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Canvas::Canvas(QObject *parent):
    QGraphicsScene (parent)
{
    /* Initializations */

    // Window sizes
    sizeX = 600;
    sizeY = 600;


    // Qimage size is the size of the grid
    image = QImage(5, 5, QImage::Format_RGB32);

    // Testing setting individual pixels
    for(int i = 0; i< 5; i++) {
        for(int j =0; j < 5; j++) {
            image.setPixel(i, j, qRgb(100*i,100*j, 200));
        }
    }

    updatePixmap();

    qInfo() << "Pixmap defined " << pixmap;

}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    QPointF tPoint = convertToPoint(mouseEvent->scenePos());
    qInfo() << "Clicked mouse at " << tPoint;
    setPixel(tPoint.x(), tPoint.y(), qRgb(0, 0, 0));
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Canvas::setPixel(int x, int y, QRgb rgb)
{
    image.setPixel(x, y, rgb);
    updatePixmap();
}

void Canvas::updatePixmap() {
    //Instead of scaling pixmap, scale qimage
    pixmap = pixmap.fromImage(image.scaled(sizeX,sizeY));
    this->addPixmap(pixmap);
}

QPointF Canvas::convertToPoint(QPointF scaledPos) {
    int xPos =(int) (scaledPos.x() * 5) / sizeX;
    int yPos = (int) (scaledPos.y() * 5) / sizeY;
    return QPointF(xPos, yPos);
}
