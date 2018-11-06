#include "canvas.h"
#include <QDebug>

Canvas::Canvas(QObject *parent):
    QGraphicsScene (parent)
{
    /* Initializations */
    setStickyFocus(true);

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
    QPointF pointPressed = convertToPoint(mouseEvent->scenePos());
    qInfo() << "CANVAS: Clicked mouse at " << mouseEvent->screenPos() << " which is "<< pointPressed;
    emit mousePressed(pointPressed);
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    QPointF pointMoved = convertToPoint(mouseEvent->screenPos());
    qInfo() << "CANVAS: Mouse moved to " << mouseEvent->screenPos() << " which is " << pointMoved;
    emit mouseMoved(pointMoved);
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
    QPointF pointReleased = convertToPoint(mouseEvent->scenePos());
    qInfo() << "CANVAS: Released mouse at " << pointReleased;
    emit mouseReleased(pointReleased);
}

//void Canvas::setPixel(int x, int y, QRgb rgb)
//{
//    image.setPixel(x, y, rgb);
//    updatePixmap();
//}

void Canvas::updatePixmap() {
    //Instead of scaling pixmap, scale qimage
    pixmap = convertImageToPixmap(image);
    qInfo() << "CANVAS: Pixmap defined " << pixmap;

    this->addPixmap(pixmap);
}

QPointF Canvas::convertToPoint(QPointF scaledPos) {
    int rX = scaledPos.x();
    int rY = scaledPos.y();

    int xPos =(int) (rX * gridX) / windowSizeX;
    int yPos = (int) (rY * gridY) / windowSizeY;
    return QPointF(xPos, yPos);
}

void Canvas::setImage(QImage* image) {
    this->image = *image;
    updatePixmap();
}
