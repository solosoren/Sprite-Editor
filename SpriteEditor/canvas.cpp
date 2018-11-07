#include "canvas.h"
#include <QDebug>

Canvas::Canvas(QObject *parent):
    QGraphicsScene (parent)
{
    /* Initializations */
    setStickyFocus(true);

    makeNewEmptyImage();
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    QPointF pointPressed = convertToPoint(mouseEvent->scenePos());
    qInfo() << "CANVAS: Clicked mouse at " << pointPressed;
    emit mousePressed(pointPressed);
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    QPointF pointMoved = convertToPoint(mouseEvent->scenePos());
    qInfo() << "CANVAS: Mouse moved to " << pointMoved;
    emit mouseMoved(pointMoved);
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    QPointF pointReleased = convertToPoint(mouseEvent->scenePos());
    qInfo() << "CANVAS: Released mouse at " << pointReleased;
    emit mouseReleased(pointReleased);
}

void Canvas::updatePixmap() {
    //Instead of scaling pixmap, scale qimage
    pixmap = convertImageToPixmapWithGridLines(image->copy());
    qInfo() << "CANVAS: Pixmap defined " << pixmap;

    this->addPixmap(pixmap);
}

QPointF Canvas::convertToPoint(QPointF scaledPos) {
    int rX = scaledPos.x();
    int rY = scaledPos.y();

    int xPos =(int) (rX * gridSizeX) / windowSizeX;
    int yPos = (int) (rY * gridSizeY) / windowSizeY;
    if(xPos < 0) {
        xPos = 0;
    }
    if(yPos < 0) {
        yPos = 0;
    }
    if(xPos >= gridSizeX) {
        xPos= gridSizeX - 1;
    }
    if(yPos >= gridSizeY) {
        yPos = gridSizeY - 1;
    }
    return QPointF(xPos, yPos);
}

void Canvas::setImage(QImage* image) {
    this->image = image;
    updatePixmap();
}

QImage* Canvas::getImage(){
    return image;
}

QImage* Canvas::makeNewEmptyImage() {
    image = new QImage(gridSizeX, gridSizeY, QImage::Format_ARGB32);

    // Initializes empty grid
    for(int i = 0; i< gridSizeX; i++) {
        for(int j =0; j < gridSizeY; j++) {
            image->setPixelColor(i, j, QColor(0,0,0,0));
        }
    }

    updatePixmap();

    return image;
}
