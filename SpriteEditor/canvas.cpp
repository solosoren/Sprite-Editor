#include "canvas.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Canvas::Canvas(QObject *parent):
    QGraphicsScene (parent)
{
    /* Initializations */

    catchPixels = false;


    // Qimage size is the size of the grid
    image = QImage(5, 5, QImage::Format_RGB32);

    // Testing setting individual pixels
    for(int i = 0; i< 5; i++) {
        for(int j =0; j < 5; j++) {
            image.setPixel(i, j, qRgb(100*i,100*j, 200));
        }
    }

    updatePixmap();
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    catchPixels = true;
    QPointF tPoint = convertToPoint(mouseEvent->scenePos());
    qInfo() << "CANVAS: Clicked mouse at " << tPoint;
    setPixel(tPoint.x(), tPoint.y(), qRgb(0, 0, 0));
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    if(catchPixels) {
        // Record pixels into the set touchedPixels
        qInfo() << "CANVAS: Mouse moved to " << convertToPoint(mouseEvent->scenePos());
    }
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    catchPixels = false;
    qInfo() << "CANVAS: Released mouse at " << convertToPoint(mouseEvent->scenePos());
}

void Canvas::setPixel(int x, int y, QRgb rgb)
{
    image.setPixel(x, y, rgb);
    updatePixmap();
}

void Canvas::updatePixmap() {
    //Instead of scaling pixmap, scale qimage
    pixmap = convertImageToPixmap(image);
    this->addPixmap(pixmap);

    qInfo() << "Pixmap defined " << pixmap;
}

QPointF Canvas::convertToPoint(QPointF scaledPos) {
    int xPos =(int) (scaledPos.x() * 5) / windowSizeX;
    int yPos = (int) (scaledPos.y() * 5) / windowSizeY;
    return QPointF(xPos, yPos);
}
